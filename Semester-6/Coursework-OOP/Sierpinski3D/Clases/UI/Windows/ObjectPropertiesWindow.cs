using System.Numerics;
using ImGuiNET;
using Sierpinski3D_Raymarching.Scene;

namespace Sierpinski3D_Raymarching.UI;

public class ObjectPropertiesWindow : IUIWindow
{
    private readonly SierpinskiFractal _fractal;
    public UIColumn Column => UIColumn.Left;

    public ObjectPropertiesWindow(SierpinskiFractal fractal)
    {
        _fractal = fractal;
    }

    public void Render(ref float сolumnY, float padding)
    {
        float windowWidth = 300.0f;

        ImGui.SetNextWindowPos(new Vector2(padding, сolumnY), ImGuiCond.Always);
        ImGui.SetNextWindowSize(new Vector2(windowWidth, 0), ImGuiCond.Always);     
        
        ImGui.Begin("Object Properties");
        
        ImGui.PushItemWidth(ImGui.GetContentRegionAvail().X);
        
        ImGui.Text("Iterations (Depth)");
        ImGui.SliderInt("##D1", ref _fractal.Iterations, 0, _fractal.MaxIterations);
        
        ImGui.Text("LOD Smoothness");
        ImGui.SliderFloat("##S1", ref _fractal.LodFactor, 0.0f, 1.0f);
        
        ImGui.Separator();
        ImGui.Text("Vertex Colors");
        
        ImGui.Indent(5.0f);

        ImGui.Text("Vertex 1 Color");
        ImGui.ColorEdit3("##C1", ref _fractal.Color1);

        ImGui.Text("Vertex 2 Color");
        ImGui.ColorEdit3("##C2", ref _fractal.Color2);

        ImGui.Text("Vertex 3 Color");
        ImGui.ColorEdit3("##C3", ref _fractal.Color3);

        ImGui.Text("Vertex 4 Color");
        ImGui.ColorEdit3("##C4", ref _fractal.Color4);

        ImGui.Unindent(5.0f);
        
        UIManager.AdvanceY(ref сolumnY, padding);

        ImGui.End();
    }
}