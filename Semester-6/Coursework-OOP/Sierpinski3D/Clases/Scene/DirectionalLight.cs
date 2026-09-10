using System.Numerics;

namespace Sierpinski3D_Raymarching.Scene;

public class DirectionalLight
{
    public Vector3 Direction { get; set; } = Vector3.Normalize(new(0.5f, 1.0f, 0.3f));
    public Vector3 Color { get; set; } = new(1.0f, 0.95f, 0.8f);
    public float Intensity { get; set; } = 1.0f;
}