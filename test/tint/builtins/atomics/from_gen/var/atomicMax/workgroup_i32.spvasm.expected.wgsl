var<private> local_invocation_index_1 : u32;

var<workgroup> arg_0 : atomic<i32>;

fn atomicMax_a89cc3() {
  var arg_1 : i32 = 0i;
  var res : i32 = 0i;
  arg_1 = 1i;
  let x_19 : i32 = arg_1;
  let x_15 : i32 = atomicMax(&(arg_0), x_19);
  res = x_15;
  return;
}

fn compute_main_inner(local_invocation_index : u32) {
  atomicStore(&(arg_0), 0i);
  workgroupBarrier();
  atomicMax_a89cc3();
  return;
}

fn compute_main_1() {
  let x_33 : u32 = local_invocation_index_1;
  compute_main_inner(x_33);
  return;
}

@compute @workgroup_size(1i, 1i, 1i)
fn compute_main(@builtin(local_invocation_index) local_invocation_index_1_param : u32) {
  local_invocation_index_1 = local_invocation_index_1_param;
  compute_main_1();
}
