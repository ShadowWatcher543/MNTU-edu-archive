using System;
using System.Numerics;
using Silk.NET.Input;

namespace Sierpinski3D_Raymarching.Scene;

public class Camera
{
    static private Vector3 standartPosition = new(-3.5f, 3.5f, 3.5f); 
    static private Vector2 standartRotation = new((float)(45.0f*Math.PI/180), (float)(-45.0f*Math.PI/180)); 
    
    public Vector3 Position = standartPosition; 
    public Vector2 Rotation = standartRotation;
    public float MoveSpeed { get; private set; } = 5.0f;
    public float MinSpeed { get; set; } = 0.0001f;
    public float MaxSpeed { get; set; } = 50.0f;
    public float ZoomFactor { get; set; } = 1.30f;
    
    public bool IsCursorCaptured;
    private Vector2 _lastMousePos;

    public Vector3 Forward => new(
        MathF.Sin(Rotation.X) * MathF.Cos(Rotation.Y),
        MathF.Sin(Rotation.Y),
        -MathF.Cos(Rotation.X) * MathF.Cos(Rotation.Y)
    );

    public Vector3 Right => Vector3.Normalize(Vector3.Cross(Forward, Vector3.UnitY));

    public void ToggleCursorCapture(IMouse mouse)
    {
        IsCursorCaptured = !IsCursorCaptured;
        if (mouse != null)
        {
            mouse.Cursor.CursorMode = IsCursorCaptured ? CursorMode.Raw : CursorMode.Normal;
            _lastMousePos = mouse.Position;
        }
    }

    public void ProcessMouseMove(Vector2 position)
    {
        if (!IsCursorCaptured) return;

        Vector2 delta = position - _lastMousePos;
        _lastMousePos = position;

        float sensitivity = 0.002f;
        Rotation.X += delta.X * sensitivity;
        Rotation.Y -= delta.Y * sensitivity;

        Rotation.Y = Math.Clamp(Rotation.Y, -1.55f, 1.55f);
        
        const float twoPi = MathF.PI * 2.0f;
        Rotation.X %= twoPi;
        if (Rotation.X < 0.0f)
        {
            Rotation.X += twoPi;
        }
    }
    
    public void ProcessMouseScroll(float scrollOffsetY)
    {
        if (MathF.Abs(scrollOffsetY) < 0.01f) return;

        if (scrollOffsetY > 0) { MoveSpeed *= ZoomFactor; }
        else if (scrollOffsetY < 0) { MoveSpeed /= ZoomFactor; }

        MoveSpeed = Math.Clamp(MoveSpeed, MinSpeed, MaxSpeed);
    }

    public void ProcessInput(IKeyboard keyboard, float deltaTime)
    {
        if (keyboard == null || !IsCursorCaptured) return;

        float velocity = MoveSpeed * deltaTime;

        if (keyboard.IsKeyPressed(Key.W)) Position += Forward * velocity;
        if (keyboard.IsKeyPressed(Key.S)) Position -= Forward * velocity;
        if (keyboard.IsKeyPressed(Key.A)) Position -= Right * velocity;
        if (keyboard.IsKeyPressed(Key.D)) Position += Right * velocity;
        if (keyboard.IsKeyPressed(Key.Space)) Position.Y += velocity;
        if (keyboard.IsKeyPressed(Key.ShiftLeft)) Position.Y -= velocity;
    }
    
    public void ApplyUniforms(Graphics.Shader shader)
    {
        shader.SetUniform("uCameraPos", Position);
        shader.SetUniform("uCameraTarget", Position + Forward);
    }
    
    public void Reset()
    {
        Position = standartPosition;
        Rotation = standartRotation;
    }
}