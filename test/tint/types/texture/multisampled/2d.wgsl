@group(0) @binding(0) var t_f : texture_multisampled_2d<f32>;
@group(0) @binding(1) var t_i : texture_multisampled_2d<i32>;
@group(0) @binding(2) var t_u : texture_multisampled_2d<u32>;

@stage(compute) @workgroup_size(1)
fn main() {
  _ = t_f;
  _ = t_i;
  _ = t_u;
}
