SKIP: FAILED

#version 310 es

uniform highp samplerCubeArray arg_1_arg_2;

void textureGather_751f8a() {
  vec3 arg_3 = vec3(1.0f);
  int arg_4 = 1;
  vec4 res = textureGather(arg_1_arg_2, vec4(arg_3, float(arg_4)), 1);
}

vec4 vertex_main() {
  textureGather_751f8a();
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
Error parsing GLSL shader:
ERROR: 0:3: 'samplerCubeArray' : Reserved word. 
ERROR: 0:3: '' : compilation terminated 
ERROR: 2 compilation errors.  No code generated.



#version 310 es
precision mediump float;

uniform highp samplerCubeArray arg_1_arg_2;

void textureGather_751f8a() {
  vec3 arg_3 = vec3(1.0f);
  int arg_4 = 1;
  vec4 res = textureGather(arg_1_arg_2, vec4(arg_3, float(arg_4)), 1);
}

void fragment_main() {
  textureGather_751f8a();
}

void main() {
  fragment_main();
  return;
}
Error parsing GLSL shader:
ERROR: 0:4: 'samplerCubeArray' : Reserved word. 
ERROR: 0:4: '' : compilation terminated 
ERROR: 2 compilation errors.  No code generated.



#version 310 es

uniform highp samplerCubeArray arg_1_arg_2;

void textureGather_751f8a() {
  vec3 arg_3 = vec3(1.0f);
  int arg_4 = 1;
  vec4 res = textureGather(arg_1_arg_2, vec4(arg_3, float(arg_4)), 1);
}

void compute_main() {
  textureGather_751f8a();
}

layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
void main() {
  compute_main();
  return;
}
Error parsing GLSL shader:
ERROR: 0:3: 'samplerCubeArray' : Reserved word. 
ERROR: 0:3: '' : compilation terminated 
ERROR: 2 compilation errors.  No code generated.



