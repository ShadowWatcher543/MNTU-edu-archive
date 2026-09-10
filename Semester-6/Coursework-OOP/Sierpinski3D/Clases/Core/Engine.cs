using System;
using System.IO;
using System.Numerics;
using ImGuiNET;
using Silk.NET.Input;
using Silk.NET.Maths;
using Silk.NET.OpenGL;
using Silk.NET.OpenGL.Extensions.ImGui;
using Sierpinski3D_Raymarching.Graphics;
using Sierpinski3D_Raymarching.Scene;
using Sierpinski3D_Raymarching.UI;

namespace Sierpinski3D_Raymarching.Core;

public class Engine
{
    private readonly WindowService _windowService;
    private GL _gl;
    private IInputContext _input;
    private ImGuiController _imGuiController;
    private UIManager _uiManager;

    private bool _shouldClose;

    private Graphics.Shader _shader; 
    private ScreenQuad _quad;

    public Camera Camera { get; } = new();
    public SierpinskiFractal Fractal { get; } = new();
    public SceneEnvironment Environment { get; } = new();

    public Engine()
    {
        _windowService = new WindowService("3D Sierpinski Raymarching", 1920, 1080); 
        _windowService.OnLoad += Initialize;
        _windowService.OnUpdate += Update;
        _windowService.OnRender += Render;
        _windowService.OnResize += Resize;
        _windowService.OnClosing += Cleanup;
    }

    public void Start() => _windowService.Run();

    private void Initialize()
    {
        _gl = GL.GetApi(_windowService.NativeWindow); 
        _input = _windowService.NativeWindow.CreateInput(); 

        if (_input.Keyboards.Count > 0)
        {
            _input.Keyboards[0].KeyDown += (kb, key, _) =>
            {
                if (key == Key.Escape) _shouldClose = true;
                if (key == Key.AltLeft || key == Key.AltRight) 
                    Camera.ToggleCursorCapture(_input.Mice.Count > 0 ? _input.Mice[0] : null);
            };
        }

        if (_input.Mice.Count > 0)
        {
            var mouse = _input.Mice[0];

            // обробка руху миші
            mouse.MouseMove += (_, pos) => Camera.ProcessMouseMove(pos); 

            // Обробка прокрутки коліщатка
            mouse.Scroll += (_, wheel) =>
            {
                if (!ImGuiNET.ImGui.GetIO().WantCaptureMouse) { Camera.ProcessMouseScroll(wheel.Y); }
            };
        }
        
        _imGuiController = new ImGuiController(_gl, _windowService.NativeWindow, _input); 
        _uiManager = new UIManager(_imGuiController);
        _uiManager.padding = 2.0f;
        
        // Реєстрація вікон меню
        _uiManager.RegisterWindow(new DebugWindow(Camera, Environment));
        _uiManager.RegisterWindow(new InfoWindow(Camera));
        _uiManager.RegisterWindow(new ObjectPropertiesWindow(Fractal));
        _uiManager.RegisterWindow(new EnvironmentWindow(Environment, Fractal));
        

        string baseDir = AppDomain.CurrentDomain.BaseDirectory; 
        string vertPath = Path.Combine(baseDir, "Shaders", "vert_screen.glsl");
        string fragPath = Path.Combine(baseDir, "Shaders", "frag_sierpinski.glsl");

        if (!File.Exists(vertPath))
        {
            vertPath = Path.Combine(Directory.GetCurrentDirectory(), "Shaders", "vert_screen.glsl"); 
            fragPath = Path.Combine(Directory.GetCurrentDirectory(), "Shaders", "frag_sierpinski.glsl");
        }

        _shader = new Graphics.Shader(_gl, vertPath, fragPath); 
        _quad = new ScreenQuad(_gl);
    }

    private void Update(double deltaTime)
    {
        if (_shouldClose)
        {
            _windowService.Close();
            return;
        }
            
        float dt = (float)deltaTime; 
        _uiManager.Update(dt);

        if (_input.Keyboards.Count > 0) 
            Camera.ProcessInput(_input.Keyboards[0], dt);

        Environment.Update(dt);
        Fractal.Update(dt, Environment.IsPaused);
    }

    private void Render(double deltaTime)
    {
        _gl.Viewport(0, 0, (uint)_windowService.Size.X, (uint)_windowService.Size.Y); 
        _gl.Clear(ClearBufferMask.ColorBufferBit | ClearBufferMask.DepthBufferBit);

        _shader.Use();
        _shader.SetUniform("uResolution", new Vector2(_windowService.Size.X, _windowService.Size.Y));

        Camera.ApplyUniforms(_shader);
        Environment.ApplyUniforms(_shader);
        Fractal.ApplyUniforms(_shader);

        _quad.Render(); 
        
        _uiManager.Render();
    }

    private void Resize(Vector2D<int> size) => _gl.Viewport(size); 

    private void Cleanup()
    {
        _quad.Dispose(); 
        _shader.Dispose();
        _imGuiController.Dispose();
        _input.Dispose();
    }
}