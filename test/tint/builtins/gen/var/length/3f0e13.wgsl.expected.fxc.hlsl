SKIP: FAILED

void length_3f0e13() {
  vector<float16_t, 2> arg_0 = (float16_t(0.0h)).xx;
  float16_t res = length(arg_0);
}

struct tint_symbol {
  float4 value : SV_Position;
};

float4 vertex_main_inner() {
  length_3f0e13();
  return (0.0f).xxxx;
}

tint_symbol vertex_main() {
  const float4 inner_result = vertex_main_inner();
  tint_symbol wrapper_result = (tint_symbol)0;
  wrapper_result.value = inner_result;
  return wrapper_result;
}

void fragment_main() {
  length_3f0e13();
  return;
}

[numthreads(1, 1, 1)]
void compute_main() {
  length_3f0e13();
  return;
}
FXC validation failure:
D:\Projects\RampUp\dawn\test\tint\builtins\Shader@0x0000020BA93CCC20(2,10-18): error X3000: syntax error: unexpected token 'float16_t'
D:\Projects\RampUp\dawn\test\tint\builtins\Shader@0x0000020BA93CCC20(3,3-11): error X3000: unrecognized identifier 'float16_t'
D:\Projects\RampUp\dawn\test\tint\builtins\Shader@0x0000020BA93CCC20(3,13-15): error X3000: unrecognized identifier 'res'

