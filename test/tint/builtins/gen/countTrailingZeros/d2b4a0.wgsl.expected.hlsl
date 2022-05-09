uint4 tint_count_trailing_zeros(uint4 v) {
  uint4 x = uint4(v);
  const uint4 b16 = (bool4((x & uint4((65535u).xxxx))) ? uint4((0u).xxxx) : uint4((16u).xxxx));
  x = (x >> b16);
  const uint4 b8 = (bool4((x & uint4((255u).xxxx))) ? uint4((0u).xxxx) : uint4((8u).xxxx));
  x = (x >> b8);
  const uint4 b4 = (bool4((x & uint4((15u).xxxx))) ? uint4((0u).xxxx) : uint4((4u).xxxx));
  x = (x >> b4);
  const uint4 b2 = (bool4((x & uint4((3u).xxxx))) ? uint4((0u).xxxx) : uint4((2u).xxxx));
  x = (x >> b2);
  const uint4 b1 = (bool4((x & uint4((1u).xxxx))) ? uint4((0u).xxxx) : uint4((1u).xxxx));
  const uint4 is_zero = ((x == uint4((0u).xxxx)) ? uint4((1u).xxxx) : uint4((0u).xxxx));
  return uint4((((((b16 | b8) | b4) | b2) | b1) + is_zero));
}

void countTrailingZeros_d2b4a0() {
  uint4 res = tint_count_trailing_zeros(uint4(0u, 0u, 0u, 0u));
}

struct tint_symbol {
  float4 value : SV_Position;
};

float4 vertex_main_inner() {
  countTrailingZeros_d2b4a0();
  return float4(0.0f, 0.0f, 0.0f, 0.0f);
}

tint_symbol vertex_main() {
  const float4 inner_result = vertex_main_inner();
  tint_symbol wrapper_result = (tint_symbol)0;
  wrapper_result.value = inner_result;
  return wrapper_result;
}

void fragment_main() {
  countTrailingZeros_d2b4a0();
  return;
}

[numthreads(1, 1, 1)]
void compute_main() {
  countTrailingZeros_d2b4a0();
  return;
}
