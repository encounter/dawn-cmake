fn dpdx_e263de() {
  var res : f32 = dpdx(1.0f);
  prevent_dce = res;
}

@group(2) @binding(0) var<storage, read_write> prevent_dce : f32;

@fragment
fn fragment_main() {
  dpdx_e263de();
}
