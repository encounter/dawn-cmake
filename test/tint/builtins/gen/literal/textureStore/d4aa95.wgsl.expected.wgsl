@group(1) @binding(0) var arg_0 : texture_storage_3d<rgba32uint, write>;

fn textureStore_d4aa95() {
  textureStore(arg_0, vec3<u32>(1u), vec4<u32>(1u));
}

@vertex
fn vertex_main() -> @builtin(position) vec4<f32> {
  textureStore_d4aa95();
  return vec4<f32>();
}

@fragment
fn fragment_main() {
  textureStore_d4aa95();
}

@compute @workgroup_size(1)
fn compute_main() {
  textureStore_d4aa95();
}
