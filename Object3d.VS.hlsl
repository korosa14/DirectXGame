struct VertexShaderOutput {
	float32_t4 position : SV_POSITION;
	/*float32_t4 color : SV_TARGET0;*/
};
struct VertexShaderInput {
	float32_t4 position : POSITION0;
};

VertexShaderOutput main(VertexShaderInput input) {
	VertexShaderOutput output;
	output.position = input.position;
	return output;
}

//float4 main( float4 pos : POSITION ) : SV_POSITION
//{
//	return pos;
//}
