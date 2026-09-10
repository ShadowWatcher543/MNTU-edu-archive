using System;
using System.IO;
using System.Numerics;
using Silk.NET.OpenGL;

namespace Sierpinski3D_Raymarching.Graphics;

public class Shader : IDisposable
{
    private readonly GL _gl;
    public uint Handle { get; private set; }

    public Shader(GL gl, string vertPath, string fragPath)
    {
        _gl = gl;

        string vertCode = File.ReadAllText(vertPath);
        string fragCode = File.ReadAllText(fragPath);

        uint vert = CompileShader(ShaderType.VertexShader, vertCode);
        uint frag = CompileShader(ShaderType.FragmentShader, fragCode);

        Handle = _gl.CreateProgram();
        _gl.AttachShader(Handle, vert);
        _gl.AttachShader(Handle, frag);
        _gl.LinkProgram(Handle);

        _gl.GetProgram(Handle, ProgramPropertyARB.LinkStatus, out int status);
        if (status == 0)
        {
            throw new Exception($"Error linking shader program:\n{_gl.GetProgramInfoLog(Handle)}");
        }

        _gl.DeleteShader(vert);
        _gl.DeleteShader(frag);
    }

    private uint CompileShader(ShaderType type, string code)
    {
        uint shader = _gl.CreateShader(type);
        _gl.ShaderSource(shader, code);
        _gl.CompileShader(shader);

        _gl.GetShader(shader, ShaderParameterName.CompileStatus, out int status);
        if (status == 0)
        {
            throw new Exception($"Error compiling {type}:\n{_gl.GetShaderInfoLog(shader)}");
        }

        return shader;
    }

    public void Use() => _gl.UseProgram(Handle);

    public void SetUniform(string name, int value) => _gl.Uniform1(_gl.GetUniformLocation(Handle, name), value);
    public void SetUniform(string name, float value) => _gl.Uniform1(_gl.GetUniformLocation(Handle, name), value);
    public void SetUniform(string name, Vector2 value) => _gl.Uniform2(_gl.GetUniformLocation(Handle, name), value);
    public void SetUniform(string name, Vector3 value) => _gl.Uniform3(_gl.GetUniformLocation(Handle, name), value);

    public void Dispose() => _gl.DeleteProgram(Handle);
}