SKIP: FAILED

[numthreads(1, 1, 1)]
void unused_entry_point() {
  return;
}

static matrix<float16_t, 2, 2> m = matrix<float16_t, 2, 2>(vector<float16_t, 2>(float16_t(0.0h), float16_t(1.0h)), vector<float16_t, 2>(float16_t(2.0h), float16_t(3.0h)));
FXC validation failure:
D:\Projects\RampUp\dawn\test\tint\expressions\Shader@0x000002A196C42AF0(6,15-23): error X3000: syntax error: unexpected token 'float16_t'

