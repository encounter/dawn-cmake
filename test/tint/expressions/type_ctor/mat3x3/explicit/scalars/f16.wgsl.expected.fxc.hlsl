SKIP: FAILED

[numthreads(1, 1, 1)]
void unused_entry_point() {
  return;
}

static matrix<float16_t, 3, 3> m = matrix<float16_t, 3, 3>(vector<float16_t, 3>(float16_t(0.0h), float16_t(1.0h), float16_t(2.0h)), vector<float16_t, 3>(float16_t(3.0h), float16_t(4.0h), float16_t(5.0h)), vector<float16_t, 3>(float16_t(6.0h), float16_t(7.0h), float16_t(8.0h)));
FXC validation failure:
D:\Projects\RampUp\dawn\test\tint\expressions\Shader@0x0000018E245E0610(6,15-23): error X3000: syntax error: unexpected token 'float16_t'

