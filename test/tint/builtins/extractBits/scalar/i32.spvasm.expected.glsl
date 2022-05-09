#version 310 es

int tint_extract_bits(int v, uint offset, uint count) {
  uint s = min(offset, 32u);
  uint e = min(32u, (s + count));
  return bitfieldExtract(v, int(s), int((e - s)));
}

void f_1() {
  int v = 0;
  uint offset_1 = 0u;
  uint count = 0u;
  int x_14 = tint_extract_bits(v, offset_1, count);
  return;
}

void f() {
  f_1();
}

layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
void main() {
  f();
  return;
}
