#version 310 es

layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
void unused_entry_point() {
  return;
}
mat4x3 m = mat4x3(vec3(0.0f), vec3(0.0f), vec3(0.0f), vec3(0.0f));
