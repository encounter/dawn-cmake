@group(1) @binding(0) var arg_0 : texture_2d<f32>;

@group(1) @binding(1) var arg_1 : sampler;

fn textureSampleBias_6a9113() {
  var arg_2 = vec2<f32>();
  var arg_3 = 1.0f;
  var res : vec4<f32> = textureSampleBias(arg_0, arg_1, arg_2, arg_3);
}

@fragment
fn fragment_main() {
  textureSampleBias_6a9113();
}