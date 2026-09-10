using System.Numerics;
using Sierpinski3D_Raymarching.Graphics;

namespace Sierpinski3D_Raymarching.Scene;

public class SierpinskiFractal
{
    public int Iterations = 6;
    public int MaxIterations = 20;
    public float LodFactor = 0.5f;
    
    public Vector3 Color1 = new(1.0f, 0.0f, 0.0f);
    public Vector3 Color2 = new(0.0f, 1.0f, 0.0f);
    public Vector3 Color3 = new(0.0f, 0.0f, 0.0f);
    public Vector3 Color4 = new(0.0f, 0.0f, 1.0f);

    public bool EnableRotation = false;
    public float RotationSpeed = 0.4f;
    public float CurrentRotationAngle;

    public void Update(float dt, bool isPaused)
    {
        if (!isPaused && EnableRotation) { CurrentRotationAngle += RotationSpeed * dt; }
    }

    public void ApplyUniforms(Graphics.Shader shader)
    {
        shader.SetUniform("uIterations", Iterations);
        shader.SetUniform("uMaxIterations", MaxIterations);
        shader.SetUniform("uLodFactor", LodFactor);
        shader.SetUniform("uColor1", Color1);
        shader.SetUniform("uColor2", Color2);
        shader.SetUniform("uColor3", Color3);
        shader.SetUniform("uColor4", Color4);
        shader.SetUniform("uEnableRotation", EnableRotation ? 1 : 0);
        shader.SetUniform("uRotationSpeed", RotationSpeed);
        shader.SetUniform("uRotationAngle", CurrentRotationAngle);
    }
}