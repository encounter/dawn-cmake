#version 310 es

void tint_symbol() {
  float a = mix(1.0f, 1.0f, 1.0f);
}

layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
void main() {
  tint_symbol();
  return;
}
