fn degrees_1ad5df() {
  var arg_0 = vec2<f32>(1.0f);
  var res : vec2<f32> = degrees(arg_0);
  prevent_dce = res;
}

@group(2) @binding(0) var<storage, read_write> prevent_dce : vec2<f32>;

@vertex
fn vertex_main() -> @builtin(position) vec4<f32> {
  degrees_1ad5df();
  return vec4<f32>();
}

@fragment
fn fragment_main() {
  degrees_1ad5df();
}

@compute @workgroup_size(1)
fn compute_main() {
  degrees_1ad5df();
}
