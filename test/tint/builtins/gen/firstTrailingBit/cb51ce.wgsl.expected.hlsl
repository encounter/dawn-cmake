uint3 tint_first_trailing_bit(uint3 v) {
  uint3 x = uint3(v);
  const uint3 b16 = (bool3((x & uint3((65535u).xxx))) ? uint3((0u).xxx) : uint3((16u).xxx));
  x = (x >> b16);
  const uint3 b8 = (bool3((x & uint3((255u).xxx))) ? uint3((0u).xxx) : uint3((8u).xxx));
  x = (x >> b8);
  const uint3 b4 = (bool3((x & uint3((15u).xxx))) ? uint3((0u).xxx) : uint3((4u).xxx));
  x = (x >> b4);
  const uint3 b2 = (bool3((x & uint3((3u).xxx))) ? uint3((0u).xxx) : uint3((2u).xxx));
  x = (x >> b2);
  const uint3 b1 = (bool3((x & uint3((1u).xxx))) ? uint3((0u).xxx) : uint3((1u).xxx));
  const uint3 is_zero = ((x == uint3((0u).xxx)) ? uint3((4294967295u).xxx) : uint3((0u).xxx));
  return uint3((((((b16 | b8) | b4) | b2) | b1) | is_zero));
}

void firstTrailingBit_cb51ce() {
  uint3 res = tint_first_trailing_bit(uint3(0u, 0u, 0u));
}

struct tint_symbol {
  float4 value : SV_Position;
};

float4 vertex_main_inner() {
  firstTrailingBit_cb51ce();
  return float4(0.0f, 0.0f, 0.0f, 0.0f);
}

tint_symbol vertex_main() {
  const float4 inner_result = vertex_main_inner();
  tint_symbol wrapper_result = (tint_symbol)0;
  wrapper_result.value = inner_result;
  return wrapper_result;
}

void fragment_main() {
  firstTrailingBit_cb51ce();
  return;
}

[numthreads(1, 1, 1)]
void compute_main() {
  firstTrailingBit_cb51ce();
  return;
}
