#version 310 es

void abs_7326de() {
  uvec3 arg_0 = uvec3(1u);
  uvec3 res = arg_0;
}

vec4 vertex_main() {
  abs_7326de();
  return vec4(0.0f);
}

void main() {
  gl_PointSize = 1.0;
  vec4 inner_result = vertex_main();
  gl_Position = inner_result;
  gl_Position.y = -(gl_Position.y);
  gl_Position.z = ((2.0f * gl_Position.z) - gl_Position.w);
  return;
}
#version 310 es
precision mediump float;

void abs_7326de() {
  uvec3 arg_0 = uvec3(1u);
  uvec3 res = arg_0;
}

void fragment_main() {
  abs_7326de();
}

void main() {
  fragment_main();
  return;
}
#version 310 es

void abs_7326de() {
  uvec3 arg_0 = uvec3(1u);
  uvec3 res = arg_0;
}

void compute_main() {
  abs_7326de();
}

layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
void main() {
  compute_main();
  return;
}
