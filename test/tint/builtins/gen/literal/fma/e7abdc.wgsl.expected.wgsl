enable f16;

fn fma_e7abdc() {
  var res : vec3<f16> = fma(vec3<f16>(f16()), vec3<f16>(f16()), vec3<f16>(f16()));
}

@vertex
fn vertex_main() -> @builtin(position) vec4<f32> {
  fma_e7abdc();
  return vec4<f32>();
}

@fragment
fn fragment_main() {
  fma_e7abdc();
}

@compute @workgroup_size(1)
fn compute_main() {
  fma_e7abdc();
}
