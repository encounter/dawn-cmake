[numthreads(1, 1, 1)]
void unused_entry_point() {
  return;
}

static uint t = 0u;

uint m() {
  t = 1u;
  return uint(t);
}

void f() {
  const uint tint_symbol = m();
  float16_t v = float16_t(tint_symbol);
}
