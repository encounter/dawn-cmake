fn abs_1e9d53() {
  var arg_0 = vec2<f32>(1.0f);
  var res : vec2<f32> = abs(arg_0);
  prevent_dce = res;
}

@group(2) @binding(0) var<storage, read_write> prevent_dce : vec2<f32>;

@vertex
fn vertex_main() -> @builtin(position) vec4<f32> {
  abs_1e9d53();
  return vec4<f32>();
}

@fragment
fn fragment_main() {
  abs_1e9d53();
}

@compute @workgroup_size(1)
fn compute_main() {
  abs_1e9d53();
}
