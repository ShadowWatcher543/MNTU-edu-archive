using System;
using Silk.NET.Maths;
using Silk.NET.Windowing;

namespace Sierpinski3D_Raymarching.Core;

public class WindowService
{
    public readonly IWindow NativeWindow;
    public Vector2D<int> Size => NativeWindow.Size;

    public event Action OnLoad;
    public event Action<double> OnUpdate;
    public event Action<double> OnRender;
    public event Action<Vector2D<int>> OnResize;
    public event Action OnClosing;

    public WindowService(string title, int width, int height)
    {
        var options = WindowOptions.Default;
        options.Size = new Vector2D<int>(width, height); 
        options.Title = title; 

        NativeWindow = Window.Create(options); 
        NativeWindow.Load += () => OnLoad?.Invoke();
        NativeWindow.Update += (dt) => OnUpdate?.Invoke(dt);
        NativeWindow.Render += (dt) => OnRender?.Invoke(dt);
        NativeWindow.FramebufferResize += (size) => OnResize?.Invoke(size);
        NativeWindow.Closing += () => OnClosing?.Invoke();
    }

    public void Run() => NativeWindow.Run(); 
    public void Close() => NativeWindow.Close();
}