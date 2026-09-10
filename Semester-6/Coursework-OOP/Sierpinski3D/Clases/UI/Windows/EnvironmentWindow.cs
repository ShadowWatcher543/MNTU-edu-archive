using System.Numerics;
using ImGuiNET;
using Sierpinski3D_Raymarching.Scene;

namespace Sierpinski3D_Raymarching.UI;

public class EnvironmentWindow : IUIWindow
{
    private readonly SceneEnvironment _environment;
    private readonly SierpinskiFractal _fractal;
    
    public UIColumn Column => UIColumn.Left;

    public EnvironmentWindow(SceneEnvironment environment, SierpinskiFractal fractal)
    {
        _environment = environment;
        _fractal = fractal;
    }

    public void Render(ref float columnY, float padding)
    {
        float windowWidth = 300.0f;

        ImGui.SetNextWindowPos(new Vector2(padding, columnY), ImGuiCond.Always);
        ImGui.SetNextWindowSize(new Vector2(windowWidth, 0), ImGuiCond.Always);

        ImGui.Begin("Environment & Animation");
        
        bool isPaused = _environment.IsPaused;
        if (ImGui.Checkbox("Pause Global Time", ref isPaused)) { _environment.IsPaused = isPaused; }

        ImGui.Separator();

        ImGui.Text("Object Rotation");
        ImGui.Checkbox("Enable Rotation", ref _fractal.EnableRotation);
        if (_fractal.EnableRotation)
        {
            ImGui.Text("Rotation Speed");
            ImGui.SliderFloat("##Rotation Speed", ref _fractal.RotationSpeed, -2.0f, 2.0f);
        }

        ImGui.Separator();
        ImGui.Text("Lighting (Sun)");
        
        bool enableAnim = _environment.EnableLightAnim;
        if (ImGui.Checkbox("Animate Light", ref enableAnim)) { _environment.EnableLightAnim = enableAnim; }

        if (_environment.EnableLightAnim)
        {
            float lightSpeed = _environment.LightSpeed;
            ImGui.Text("Light Speed");
            if (ImGui.SliderFloat("##Light Speed", ref lightSpeed, 0.0f, 2.0f)) { _environment.LightSpeed = lightSpeed; }
        }
        else
        {
            Vector3 lightDir = _environment.MainLight.Direction;
            ImGui.Text("Sun Direction");
            if (ImGui.DragFloat3("##Sun Direction", ref lightDir, 0.05f, -1.0f, 1.0f))
            {
                if (lightDir.LengthSquared() > 0.0001f) { _environment.MainLight.Direction = Vector3.Normalize(lightDir); }
            }
        }

        Vector3 lightColor = _environment.MainLight.Color;
        ImGui.Text("Sun Color");
        if (ImGui.ColorEdit3("##Sun Color", ref lightColor))
        {
            _environment.MainLight.Color = lightColor;
        }

        float intensity = _environment.MainLight.Intensity;
        ImGui.Text("Sun Intensity");
        if (ImGui.SliderFloat("##Sun Intensity", ref intensity, 0.0f, 5.0f))
        {
            _environment.MainLight.Intensity = intensity;
        }
        
        bool sky = _environment.Skybox.IsEnabled;
        if (ImGui.Checkbox("Skybox", ref sky)) 
            _environment.Skybox.IsEnabled = sky;

        bool ground = _environment.Ground.IsEnabled;
        if (ImGui.Checkbox("Ground Plane", ref ground)) 
            _environment.Ground.IsEnabled = ground;

        ImGui.Separator();

        bool useLightColor = _environment.UseLightColor;
        if (ImGui.Checkbox("Multiply Surface by Sun Color", ref useLightColor)) 
            _environment.UseLightColor = useLightColor;

        if (!_environment.Skybox.IsEnabled) ImGui.BeginDisabled();

        bool enableFog = _environment.EnableFog;
        if (ImGui.Checkbox("Distance Fog", ref enableFog)) 
            _environment.EnableFog = enableFog;

        if (!_environment.Skybox.IsEnabled) ImGui.EndDisabled();
        
        UIManager.AdvanceY(ref columnY, padding);
        
        ImGui.End();
    }
}