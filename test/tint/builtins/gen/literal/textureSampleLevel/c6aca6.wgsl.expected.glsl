#version 310 es

uniform highp sampler2D arg_0_arg_1;

void textureSampleLevel_c6aca6() {
  vec4 res = textureLod(arg_0_arg_1, vec2(0.0f), 1.0f);
}

vec4 vertex_main() {
  textureSampleLevel_c6aca6();
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

uniform highp sampler2D arg_0_arg_1;

void textureSampleLevel_c6aca6() {
  vec4 res = textureLod(arg_0_arg_1, vec2(0.0f), 1.0f);
}

void fragment_main() {
  textureSampleLevel_c6aca6();
}

void main() {
  fragment_main();
  return;
}
#version 310 es

uniform highp sampler2D arg_0_arg_1;

void textureSampleLevel_c6aca6() {
  vec4 res = textureLod(arg_0_arg_1, vec2(0.0f), 1.0f);
}

void compute_main() {
  textureSampleLevel_c6aca6();
}

layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
void main() {
  compute_main();
  return;
}
