@group(1) @binding(0) var arg_0 : texture_depth_2d_array;

@group(1) @binding(1) var arg_1 : sampler_comparison;

fn textureSampleCompare_dd431d() {
  var arg_2 = vec2<f32>();
  var arg_3 = 1;
  var arg_4 = 1.0f;
  var res : f32 = textureSampleCompare(arg_0, arg_1, arg_2, arg_3, arg_4);
}

@fragment
fn fragment_main() {
  textureSampleCompare_dd431d();
}
