#version 330 core

out vec4 FragColor;

//  CONFIG DEFINES 
#define MAX_STEPS 160
#define MAX_DIST 50.0
#define SURF_DIST 0.0005
#define STEP_MULT 0.5

//  UNIFORMS: Screen & Camera 
uniform vec2 uResolution;
uniform float uTime;
uniform vec3 uCameraPos;
uniform vec3 uCameraTarget;

//  UNIFORMS: Fractal & LOD 
uniform int uIterations;
uniform int uMaxIterations;
uniform float uLodFactor;

uniform vec3 uColor1;
uniform vec3 uColor2;
uniform vec3 uColor3;
uniform vec3 uColor4;

uniform float uRotationAngle;

//  UNIFORMS: GroundPlane 
uniform int uGroundEnabled;
uniform float uGroundHeight;
uniform vec3 uGroundColor;

//  UNIFORMS: Skybox & MainLight 
uniform int uSkyEnabled;
uniform vec3 uSkyColor;
uniform vec3 uHorizonColor;
uniform vec3 uSunDirection;
uniform vec3 uSunColor;

//  UNIFORMS: Toggles for Lighting & Fog 
uniform bool uUseLightColor;
uniform bool uEnableFog;     

//  HELPER MATH 
mat2 rotate2D(float angle)
{
    float s = sin(angle);
    float c = cos(angle);
    return mat2(c, -s, s, c);
}

vec3 transformSpace(vec3 p)
{
    p.xz *= rotate2D(uRotationAngle * 0.5);
    p.xy *= rotate2D(uRotationAngle * 0.3);
    return p;
}

vec3 getGlobalTetrahedronColor(vec3 localP)
{
    const vec3 v1 = vec3( 1.0,  1.0,  1.0);
    const vec3 v2 = vec3(-1.0, -1.0,  1.0);
    const vec3 v3 = vec3( 1.0, -1.0, -1.0);
    const vec3 v4 = vec3(-1.0,  1.0, -1.0);

    float d1 = length(localP - v1);
    float d2 = length(localP - v2);
    float d3 = length(localP - v3);
    float d4 = length(localP - v4);

    float w1 = exp(-1.5 * d1);
    float w2 = exp(-1.5 * d2);
    float w3 = exp(-1.5 * d3);
    float w4 = exp(-1.5 * d4);

    float totalWeight = w1 + w2 + w3 + w4;
    return (uColor1 * w1 + uColor2 * w2 + uColor3 * w3 + uColor4 * w4) / max(totalWeight, 0.0001);
}

int getDiscreteLOD(float rayDist)
{
    if (uIterations <= 0) return 0;
    if (uLodFactor <= 0.0001) return uIterations;

    int minIters = min(uIterations, 3);

    float effectiveDist = max(0.0, rayDist - 1.0 / (float(uIterations) / 3.0));
    float iterNorm = float(uIterations) / 16.0;
    float baseAutoSensitivity = sqrt(iterNorm) * float(uIterations) * 0.15 * float(uIterations) / 3.0;
    float lodSensitivity = baseAutoSensitivity * uLodFactor;

    int dropIters = int(effectiveDist * lodSensitivity);
    int targetIters = uIterations - dropIters;

    return int(clamp(float(targetIters), float(minIters), float(uIterations)));
}

//  SDF FRACTAL 
float sdSierpinskiTetrahedron(vec3 p, float size, int iters)
{
    p /= size;

    const float Scale = 2.0;
    const vec3 v1 = vec3(1.0, 1.0, 1.0);

    for(int n = 0; n < iters; n++)
    {
        if(p.x + p.y < 0.0) p.xy = -p.yx;
        if(p.x + p.z < 0.0) p.xz = -p.zx;
        if(p.y + p.z < 0.0) p.zy = -p.yz;

        p = p * Scale - v1 * (Scale - 1.0);
    }

    float dTetrahedron = (max(abs(p.x + p.y) - p.z, abs(p.x - p.y) + p.z) - 1.0) * 0.57735027;
    return dTetrahedron * exp2(-float(iters)) * size;
}

//  GLOBAL SCENE MAP 
float mapScene(vec3 p, float rayDist, out vec3 outAlbedo, out int hitType)
{
    // 1. Фрактал (hitType = 1)
    vec3 localP = transformSpace(p);
    int currentLOD = getDiscreteLOD(rayDist);
    float dFractal = sdSierpinskiTetrahedron(localP, 1.5, currentLOD);

    float minDist = dFractal;
    outAlbedo = getGlobalTetrahedronColor(localP / 1.5);
    hitType = 1;

    //  Ground Plane 
    if (uGroundEnabled == 1)
    {
        float dGround = p.y - uGroundHeight;
        if (dGround < minDist)
        {
            minDist = dGround;
            outAlbedo = uGroundColor;
            hitType = 2;
        }
    }

    return minDist;
}

float mapScene(vec3 p, float rayDist)
{
    vec3 dummyAlbedo;
    int dummyType;
    return mapScene(p, rayDist, dummyAlbedo, dummyType);
}

vec3 calcNormal(vec3 p, float rayDist, float eps)
{
    vec2 e = vec2(1.0, -1.0) * 0.5773;
    float normalEps = eps * 2.0;
    return normalize
    (
        e.xyy * mapScene(p + e.xyy * normalEps, rayDist) +
        e.yyx * mapScene(p + e.yyx * normalEps, rayDist) +
        e.yxy * mapScene(p + e.yxy * normalEps, rayDist) +
        e.xxx * mapScene(p + e.xxx * normalEps, rayDist)
    );
}

float calcShadow(vec3 ro, vec3 rd, float mint, float maxt, float k, float rayDist)
{
    float res = 1.0;
    float t = mint;
    for(int i = 0; i < 24; i++)
    {
        float h = mapScene(ro + rd * t, rayDist + t);
        if(h < 0.001) return 0.0;

        res = min(res, k * h / t);

        t += clamp(h, 0.01, 0.5);
        if(t > maxt) break;
    }
    return clamp(res, 0.0, 1.0);
}

//  RENDER SKYBOX 
vec3 renderSky(vec3 rd)
{
    if (uSkyEnabled == 0) return vec3(0.03);

    float skyGradient = clamp(rd.y * 0.5 + 0.5, 0.0, 1.0);
    vec3 sky = mix(uHorizonColor, uSkyColor, skyGradient);

    vec3 L = normalize(uSunDirection);
    float sunAmount = max(dot(rd, L), 0.0);
    float sunDisk = pow(sunAmount, 256.0);
    float sunGlow = pow(sunAmount, 8.0) * 0.3;

    return sky + uSunColor * (sunDisk + sunGlow);
}

void main()
{
    vec2 uv = (gl_FragCoord.xy / uResolution) * 2.0 - 1.0;
    uv.x *= uResolution.x / uResolution.y;

    vec3 rayOrigin = uCameraPos;
    vec3 forward = normalize(uCameraTarget - uCameraPos);
    vec3 right = normalize(cross(forward, vec3(0.0, 1.0, 0.0)));
    vec3 up = cross(right, forward);

    vec3 rayDirect = normalize(forward + uv.x * right + uv.y * up);

    int baseHighScale = max(0, uIterations - 10);
    float baseHitEps = SURF_DIST * exp2(-float(baseHighScale));
    float stepMult = STEP_MULT;

    float t = 0.0;
    bool hit = false;
    vec3 albedo = vec3(0.0);
    int hitType = 0;
    int stepCount = 0;

    float minD = 10000.0;
    int smallStepCounter = 0;

    for (int i = 0; i < MAX_STEPS; i++)
    {
        stepCount = i;
        vec3 p = rayOrigin + rayDirect * t;

        vec3 currentAlbedo;
        int currentType;
        float d = mapScene(p, t, currentAlbedo, currentType);

        albedo = currentAlbedo;
        minD = min(minD, d);

        float currentHitEps = baseHitEps * (1.0 + t * 0.2);

        if (d < currentHitEps)
        {
            hit = true;
            hitType = currentType;
            break;
        }
        
        if (d < currentHitEps * 3.0)
        {
            smallStepCounter++;
            if (smallStepCounter > 8) break;
        }
        else
        {
            smallStepCounter = 0;
        }

        t += d * stepMult;
        if (t > MAX_DIST) break;
    }

    vec3 col = vec3(0.0);

    if (t < MAX_DIST)
    {
        vec3 p = rayOrigin + rayDirect * t;
        float finalHitEps = baseHitEps * (1.0 + t * 0.2);

        // Повноцінний колір з освітленням
        vec3 n = calcNormal(p, t, finalHitEps);
        vec3 lightDir = normalize(uSunDirection);

        float diff = max(dot(n, lightDir), 0.0);
        float shadow = calcShadow(p + n * 0.01, lightDir, 0.01, 8.0, 16.0, t);
        float amb = 0.2;

        vec3 activeLightColor = uUseLightColor ? uSunColor : vec3(1.0);
        vec3 litColor = albedo * ((amb + diff * shadow) * activeLightColor);

        // Градієнт затінення
        float stepRatio = float(stepCount) / float(MAX_STEPS);
        float occ = exp(-stepRatio * 2.5);
        vec3 depthBg = (uSkyEnabled == 1) ? uHorizonColor * 0.2 : vec3(0.03);
        vec3 ambientColor = mix(depthBg, albedo * 0.3, occ);

        // Плавний безшовний градієнт
        float hitFactor = smoothstep(finalHitEps * 4.0, finalHitEps, minD);
        col = mix(ambientColor, litColor, hitFactor);

        if (uSkyEnabled == 1 && uEnableFog)
        {
            float fogFactor = 1.0 - exp(-t * 0.03);
            col = mix(col, uHorizonColor, fogFactor);
        }
    }
    else
    {
        col = renderSky(rayDirect);
    }

    FragColor = vec4(pow(col, vec3(1.0 / 2.2)), 1.0);
}