#include "Object3d.hlsli"

//struct PixelShaderOutput
//{
//	float32_t4 color : SV_TARGET0;
//};
struct Material {
	float32_t4 color;
};

ConstantBuffer<Material>gMaterial:register(b0);
struct PixelShaderOutput {
	float32_t4 color : SV_TARGET0;
};

PixelShaderOutput main(VertexShaderOutput input) {
	PixelShaderOutput output;
	output.color = gMaterial.color;
	//float32_t4(1.0, 1.0, 1.0, 1.0);
	return output;
}