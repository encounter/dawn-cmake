enable f16;

fn dot_8e40f1() {
  var res : f16 = dot(vec3<f16>(f16()), vec3<f16>(f16()));
}

@vertex
fn vertex_main() -> @builtin(position) vec4<f32> {
  dot_8e40f1();
  return vec4<f32>();
}

@fragment
fn fragment_main() {
  dot_8e40f1();
}

@compute @workgroup_size(1)
fn compute_main() {
  dot_8e40f1();
}
