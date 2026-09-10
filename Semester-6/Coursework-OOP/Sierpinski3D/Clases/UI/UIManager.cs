using System.Numerics;
using ImGuiNET;
using Silk.NET.OpenGL.Extensions.ImGui;

namespace Sierpinski3D_Raymarching.UI;

public class UIManager
{
    private readonly List<IUIWindow> _windows = new();
    private readonly ImGuiController _imGuiController;
    public float padding = 2.0f;
    
    public static void AdvanceY(ref float currentY, float padding)
    {
        Vector2 size = ImGui.GetWindowSize();
        currentY += size.Y + padding;
    }

    public UIManager(ImGuiController imGuiController)
    {
        _imGuiController = imGuiController;
    }

    public void RegisterWindow(IUIWindow window)
    {
        _windows.Add(window);
    }

    public void Update(float deltaTime)
    {
        _imGuiController.Update(deltaTime);
    }

    public void Render()
    {
        float leftColumnY = padding;
        float rightColumnY = padding;

        foreach (var window in _windows)
        {
            if (window.Column == UIColumn.Left)
            {
                window.Render(ref leftColumnY, padding);
            }
            else
            {
                window.Render(ref rightColumnY, padding);
            }
        }

        _imGuiController.Render();
    }

    public void Dispose()
    {
        _imGuiController.Dispose();
    }
}