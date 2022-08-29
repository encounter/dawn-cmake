#version 310 es
#extension GL_AMD_gpu_shader_half_float : require

void transpose_5f36bf() {
  f16mat4x3 arg_0 = f16mat4x3(f16vec3(0.0hf), f16vec3(0.0hf), f16vec3(0.0hf), f16vec3(0.0hf));
  f16mat3x4 res = transpose(arg_0);
}

vec4 vertex_main() {
  transpose_5f36bf();
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

void transpose_5f36bf() {
  f16mat4x3 arg_0 = f16mat4x3(f16vec3(0.0hf), f16vec3(0.0hf), f16vec3(0.0hf), f16vec3(0.0hf));
  f16mat3x4 res = transpose(arg_0);
}

void fragment_main() {
  transpose_5f36bf();
}

void main() {
  fragment_main();
  return;
}
#version 310 es
#extension GL_AMD_gpu_shader_half_float : require

void transpose_5f36bf() {
  f16mat4x3 arg_0 = f16mat4x3(f16vec3(0.0hf), f16vec3(0.0hf), f16vec3(0.0hf), f16vec3(0.0hf));
  f16mat3x4 res = transpose(arg_0);
}

void compute_main() {
  transpose_5f36bf();
}

layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
void main() {
  compute_main();
  return;
}
