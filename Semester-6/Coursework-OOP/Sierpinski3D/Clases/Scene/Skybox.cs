using System.Numerics;
using Silk.NET.OpenGL;

namespace Sierpinski3D_Raymarching.Scene;

public class Skybox
{
    public bool IsEnabled { get; set; } = true;
    public Vector3 SkyColor { get; set; } = new(0.4f, 0.6f, 0.9f);
    public Vector3 HorizonColor { get; set; } = new(0.7f, 0.8f, 0.9f);

    public DirectionalLight MainLight { get; }

    public Skybox(DirectionalLight mainLight)
    {
        MainLight = mainLight;
    }

    public void ApplyUniforms(Graphics.Shader shader)
    {
        shader.SetUniform("uSkyEnabled", IsEnabled ? 1 : 0);
        shader.SetUniform("uSkyColor", SkyColor);
        shader.SetUniform("uHorizonColor", HorizonColor);

        Vector3 normDir = Vector3.Normalize(MainLight.Direction);
        Vector3 finalSunColor = MainLight.Color * MainLight.Intensity;

        shader.SetUniform("uSunDirection", normDir);
        shader.SetUniform("uSunColor", finalSunColor);
    }
}