enable f16;

fn tan_d4d491() {
  var arg_0 = 1.0h;
  var res : f16 = tan(arg_0);
  prevent_dce = res;
}

@group(2) @binding(0) var<storage, read_write> prevent_dce : f16;

@vertex
fn vertex_main() -> @builtin(position) vec4<f32> {
  tan_d4d491();
  return vec4<f32>();
}

@fragment
fn fragment_main() {
  tan_d4d491();
}

@compute @workgroup_size(1)
fn compute_main() {
  tan_d4d491();
}
