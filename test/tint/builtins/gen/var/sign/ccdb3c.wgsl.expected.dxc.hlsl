RWByteAddressBuffer prevent_dce : register(u0, space2);

void sign_ccdb3c() {
  vector<float16_t, 2> arg_0 = (float16_t(1.0h)).xx;
  vector<float16_t, 2> res = vector<float16_t, 2>(sign(arg_0));
  prevent_dce.Store<vector<float16_t, 2> >(0u, res);
}

struct tint_symbol {
  float4 value : SV_Position;
};

float4 vertex_main_inner() {
  sign_ccdb3c();
  return (0.0f).xxxx;
}

tint_symbol vertex_main() {
  const float4 inner_result = vertex_main_inner();
  tint_symbol wrapper_result = (tint_symbol)0;
  wrapper_result.value = inner_result;
  return wrapper_result;
}

void fragment_main() {
  sign_ccdb3c();
  return;
}

[numthreads(1, 1, 1)]
void compute_main() {
  sign_ccdb3c();
  return;
}
