void clamp_2c251b() {
  vector<float16_t, 4> arg_0 = (float16_t(0.0h)).xxxx;
  vector<float16_t, 4> arg_1 = (float16_t(0.0h)).xxxx;
  vector<float16_t, 4> arg_2 = (float16_t(0.0h)).xxxx;
  vector<float16_t, 4> res = clamp(arg_0, arg_1, arg_2);
}

struct tint_symbol {
  float4 value : SV_Position;
};

float4 vertex_main_inner() {
  clamp_2c251b();
  return (0.0f).xxxx;
}

tint_symbol vertex_main() {
  const float4 inner_result = vertex_main_inner();
  tint_symbol wrapper_result = (tint_symbol)0;
  wrapper_result.value = inner_result;
  return wrapper_result;
}

void fragment_main() {
  clamp_2c251b();
  return;
}

[numthreads(1, 1, 1)]
void compute_main() {
  clamp_2c251b();
  return;
}
