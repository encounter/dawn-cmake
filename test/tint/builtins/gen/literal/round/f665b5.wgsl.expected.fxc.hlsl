SKIP: FAILED

void round_f665b5() {
  vector<float16_t, 4> res = round((float16_t(0.0h)).xxxx);
}

struct tint_symbol {
  float4 value : SV_Position;
};

float4 vertex_main_inner() {
  round_f665b5();
  return (0.0f).xxxx;
}

tint_symbol vertex_main() {
  const float4 inner_result = vertex_main_inner();
  tint_symbol wrapper_result = (tint_symbol)0;
  wrapper_result.value = inner_result;
  return wrapper_result;
}

void fragment_main() {
  round_f665b5();
  return;
}

[numthreads(1, 1, 1)]
void compute_main() {
  round_f665b5();
  return;
}
FXC validation failure:
D:\Projects\RampUp\dawn\test\tint\builtins\Shader@0x0000017F6B0D8810(2,10-18): error X3000: syntax error: unexpected token 'float16_t'

