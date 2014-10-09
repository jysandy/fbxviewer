#include <TexturedPhongPS.hlsli>

float4 main(PixelShaderInput input) : SV_TARGET
{
	return pixelShader(input);
}