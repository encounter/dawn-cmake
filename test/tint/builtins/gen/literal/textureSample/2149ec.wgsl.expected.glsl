#version 310 es
precision mediump float;

uniform highp sampler3D arg_0_arg_1;

void textureSample_2149ec() {
  vec4 res = textureOffset(arg_0_arg_1, vec3(0.0f), ivec3(0));
}

void fragment_main() {
  textureSample_2149ec();
}

void main() {
  fragment_main();
  return;
}
