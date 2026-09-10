using System.Numerics;
using Sierpinski3D_Raymarching.Scene;
using ImGuiNET;

namespace Sierpinski3D_Raymarching.UI;

public class InfoWindow : IUIWindow
{
    private readonly Camera _camera;
    public UIColumn Column => UIColumn.Right;

    public InfoWindow(Camera camera)
    {
        _camera = camera;
    }

    public void Render(ref float сolumnY, float padding)
    {
        var viewport = ImGui.GetMainViewport();
        float windowWidth = 290.0f;

        ImGui.SetNextWindowPos(new Vector2(viewport.Size.X - windowWidth - padding, сolumnY), ImGuiCond.Always);
        ImGui.SetNextWindowSize(new Vector2(windowWidth, 0), ImGuiCond.Always);    
        
        ImGui.Begin("Info & Controls");

        ImGui.TextWrapped($"Mouse Scrol: To change move speed");
        ImGui.Separator();
        ImGui.TextWrapped($"Mouse Mode: {(_camera.IsCursorCaptured ? "CAMERA CONTROL \n(Press ALT to unlock mouse)" : "UI MODE \n(Press ALT to lock mouse)")}");
        ImGui.Separator();
        ImGui.Text("- WASD: Move camera");
        ImGui.Text("- Space / Shift: Up / Down");
        ImGui.Text("- ESC: Exit");
        ImGui.Separator();
        ImGui.Text("Developer: Panenko Yan, aIk-43");

        if (ImGui.Button("Reset Camera"))
        {
            _camera.Reset();
        }

        UIManager.AdvanceY(ref сolumnY, padding);
        
        ImGui.End();
    }
}