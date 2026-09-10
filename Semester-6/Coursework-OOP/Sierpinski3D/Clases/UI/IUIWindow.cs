using System.Numerics;
using ImGuiNET;

namespace Sierpinski3D_Raymarching.UI;

public enum UIColumn
{
    Left,
    Right
}

public interface IUIWindow
{
    void Render(ref float сolumnY, float padding);
    UIColumn Column { get; }
    
}   