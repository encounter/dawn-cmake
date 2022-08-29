#version 310 es
#extension GL_AMD_gpu_shader_half_float : require

f16vec3 tint_radians(f16vec3 param_0) {
  return param_0 * 0.017453292519943295474hf;
}


void radians_7ea4c7() {
  f16vec3 res = tint_radians(f16vec3(0.0hf));
}

vec4 vertex_main() {
  radians_7ea4c7();
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
#extension GL_AMD_gpu_shader_half_float : require
precision mediump float;

f16vec3 tint_radians(f16vec3 param_0) {
  return param_0 * 0.017453292519943295474hf;
}


void radians_7ea4c7() {
  f16vec3 res = tint_radians(f16vec3(0.0hf));
}

void fragment_main() {
  radians_7ea4c7();
}

void main() {
  fragment_main();
  return;
}
#version 310 es
#extension GL_AMD_gpu_shader_half_float : require

f16vec3 tint_radians(f16vec3 param_0) {
  return param_0 * 0.017453292519943295474hf;
}


void radians_7ea4c7() {
  f16vec3 res = tint_radians(f16vec3(0.0hf));
}

void compute_main() {
  radians_7ea4c7();
}

layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
void main() {
  compute_main();
  return;
}
