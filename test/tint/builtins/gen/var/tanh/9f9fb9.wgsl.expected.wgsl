fn tanh_9f9fb9() {
  var arg_0 = vec3<f32>(1.0f);
  var res : vec3<f32> = tanh(arg_0);
}

@vertex
fn vertex_main() -> @builtin(position) vec4<f32> {
  tanh_9f9fb9();
  return vec4<f32>();
}

@fragment
fn fragment_main() {
  tanh_9f9fb9();
}

@compute @workgroup_size(1)
fn compute_main() {
  tanh_9f9fb9();
}
