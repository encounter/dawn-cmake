int3 value_or_one_if_zero_int3(int3 value) {
  return value == int3(0, 0, 0) ? int3(1, 1, 1) : value;
}

[numthreads(1, 1, 1)]
void f() {
  int3 a = int3(1, 2, 3);
  int3 b = int3(0, 5, 0);
  const int3 r = (a % value_or_one_if_zero_int3((b + b)));
  return;
}
