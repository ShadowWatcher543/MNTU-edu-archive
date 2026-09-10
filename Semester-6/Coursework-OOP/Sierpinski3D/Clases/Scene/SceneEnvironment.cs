using System;
using System.Numerics;
using Silk.NET.OpenGL;
using Shader = Sierpinski3D_Raymarching.Graphics.Shader;

namespace Sierpinski3D_Raymarching.Scene;

public class SceneEnvironment
{
    public bool IsPaused { get; set; } 
    public float GlobalTime { get; private set; } 
    
    // Налаштування анімації освітлення
    public bool EnableLightAnim { get; set; } = false; 
    public bool UseLightColor { get; set; } = false;
    public bool EnableFog { get; set; } = false;
    public float LightSpeed { get; set; } = 0.3f; 
    public float CurrentLightAngle { get; set; } = 0.0f;

    // Складові частини сцени (ООП)
    public DirectionalLight MainLight { get; } = new();
    public GroundPlane Ground { get; } = new();
    public Skybox Skybox { get; }
    
    public SceneEnvironment()
    {
        Skybox = new Skybox(MainLight);
    }

    public void Update(float dt)
    {
        if (IsPaused) return;

        GlobalTime += dt;

        if (EnableLightAnim)
        {
            CurrentLightAngle += LightSpeed * dt;

            MainLight.Direction = Vector3.Normalize(new Vector3(
                MathF.Cos(CurrentLightAngle),
                1.2f,
                MathF.Sin(CurrentLightAngle)
            ));
        }
    }

    public void ApplyUniforms(Shader shader)
    {
        shader.SetUniform("uUseLightColor", UseLightColor ? 1 : 0);
        shader.SetUniform("uEnableFog", EnableFog ? 1 : 0);
        
        shader.SetUniform("uSunDirection", MainLight.Direction);
        shader.SetUniform("uSunColor", MainLight.Color);
        
        Ground.ApplyUniforms(shader);
        Skybox.ApplyUniforms(shader);
    }
}