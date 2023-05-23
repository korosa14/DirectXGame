struct VertexShaderOutput {
	/*float32_t4 position: SV_POSITI;*/
	float32_t4 color : SV_TARGET0;
};
struct VertexShaderInPut {
	float32_t4 position : POSITIONO;
};

VertexShaderOutput main(VertexShanderInput input) {
	VetexShaderOutput output;
	output.position = input.position;
	return output;
}

//float4 main( float4 pos : POSITION ) : SV_POSITION
//{
//	return pos;
//}
PixelShaderOutput main() {
	PixelShaderOutput output;
	output.color = float32_t4(1.0, 1.0, 1.0, 1.0);
	return output;
}