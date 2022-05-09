Texture2D<uint4> arg_0 : register(t0, space1);

void textureLoad_6154d4() {
  uint4 res = arg_0.Load(int3(0, 0, 0));
}

struct tint_symbol {
  float4 value : SV_Position;
};

float4 vertex_main_inner() {
  textureLoad_6154d4();
  return float4(0.0f, 0.0f, 0.0f, 0.0f);
}

tint_symbol vertex_main() {
  const float4 inner_result = vertex_main_inner();
  tint_symbol wrapper_result = (tint_symbol)0;
  wrapper_result.value = inner_result;
  return wrapper_result;
}

void fragment_main() {
  textureLoad_6154d4();
  return;
}

[numthreads(1, 1, 1)]
void compute_main() {
  textureLoad_6154d4();
  return;
}
