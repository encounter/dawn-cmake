#version 310 es
#extension GL_AMD_gpu_shader_half_float : require

layout(binding = 0, std140) uniform m_block_std140_ubo {
  f16vec4 inner_0;
  f16vec4 inner_1;
  f16vec4 inner_2;
  f16vec4 inner_3;
} m;

f16mat4 load_m_inner() {
  return f16mat4(m.inner_0, m.inner_1, m.inner_2, m.inner_3);
}

void f() {
  f16mat4 p_m = load_m_inner();
  f16vec4 p_m_1 = m.inner_1;
  f16mat4 l_m = load_m_inner();
  f16vec4 l_m_1 = m.inner_1;
}

layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
void main() {
  f();
  return;
}
