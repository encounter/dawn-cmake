#version 310 es

layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
void unused_entry_point() {
  return;
}
bool t = false;
bvec4 m() {
  t = true;
  return bvec4(t);
}

void f() {
  bvec4 tint_symbol = m();
  uvec4 v = uvec4(tint_symbol);
}

