using System.Numerics;
using Silk.NET.OpenGL;

namespace Sierpinski3D_Raymarching.Scene;

public class GroundPlane
{
    public bool IsEnabled { get; set; } = true;
    public float Height { get; set; } = -3.0f;
    public Vector3 Color { get; set; } = new(0.2f, 0.2f, 0.25f);

    public void ApplyUniforms(Graphics.Shader shader)
    {
        shader.SetUniform("uGroundEnabled", IsEnabled ? 1 : 0);
        shader.SetUniform("uGroundHeight", Height);
        shader.SetUniform("uGroundColor", Color);
    }
}