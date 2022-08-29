RWByteAddressBuffer sb_rw : register(u0, space0);

int tint_atomicExchange(RWByteAddressBuffer buffer, uint offset, int value) {
  int original_value = 0;
  buffer.InterlockedExchange(offset, value, original_value);
  return original_value;
}


void atomicExchange_f2e22f() {
  int arg_1 = 0;
  int res = 0;
  arg_1 = 1;
  const int x_13 = tint_atomicExchange(sb_rw, 0u, arg_1);
  res = x_13;
  return;
}

void fragment_main_1() {
  atomicExchange_f2e22f();
  return;
}

void fragment_main() {
  fragment_main_1();
  return;
}

void compute_main_1() {
  atomicExchange_f2e22f();
  return;
}

[numthreads(1, 1, 1)]
void compute_main() {
  compute_main_1();
  return;
}
