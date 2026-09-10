using System.Numerics;
using ImGuiNET;
using Sierpinski3D_Raymarching.Scene;

namespace Sierpinski3D_Raymarching.UI;

public class DebugWindow : IUIWindow
{
    private readonly Camera _camera;
    private readonly SceneEnvironment _environment;
    public UIColumn Column => UIColumn.Right;

    public DebugWindow(Camera camera, SceneEnvironment environment)
    {
        _camera = camera;
        _environment = environment;
    }

    public void Render(ref float сolumnY, float padding)
    {
        var viewport = ImGui.GetMainViewport();
        float windowWidth = 290.0f; 

        ImGui.SetNextWindowPos(new Vector2(viewport.Size.X - windowWidth - padding, сolumnY), ImGuiCond.Always);
        ImGui.SetNextWindowSize(new Vector2(windowWidth, 0), ImGuiCond.Always);     
        
        ImGui.Begin("Debug Stats");
        
        ImGui.Text($"FPS: {1.0f / ImGui.GetIO().DeltaTime:F1}");
        ImGui.Text($"Camera Speed: {_camera.MoveSpeed:0.####} m/s");
        ImGui.Text($"Global Time: {_environment.GlobalTime:F2} s");
        
        ImGui.Separator();
        ImGui.Text($"Camera Position: X:{_camera.Position.X:F2} Y:{_camera.Position.Y:F2} Z:{_camera.Position.Z:F2}");
        
        Vector2 rotDegrees = new Vector2(
            _camera.Rotation.X * (180.0f / MathF.PI),
            _camera.Rotation.Y * (180.0f / MathF.PI)
        );
        ImGui.Text($"Camera Rotation: Yaw {rotDegrees.X:F1}°, Pitch {rotDegrees.Y:F1}°");

        ImGui.Separator();
        ImGui.TextColored(new Vector4(0.7f, 0.7f, 0.7f, 1.0f), "GPU Info (Placeholder):");
        ImGui.Text("GPU Load: N/A");
        ImGui.Text("GPU Temp: N/A");
        
        UIManager.AdvanceY(ref сolumnY, padding);
            
        ImGui.End();
    }
}