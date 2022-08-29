// Copyright 2022 The Tint Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

////////////////////////////////////////////////////////////////////////////////
// File generated by tools/src/cmd/gen
// using the template:
//   test/tint/builtins/gen/gen.wgsl.tmpl
//
// Do not modify this file directly
////////////////////////////////////////////////////////////////////////////////


enable f16;

// fn select(vec<2, f16>, vec<2, f16>, vec<2, bool>) -> vec<2, f16>
fn select_ed7c13() {
  var arg_0 = vec2<f16>(f16());
  var arg_1 = vec2<f16>(f16());
  var arg_2 = vec2<bool>(true);
  var res: vec2<f16> = select(arg_0, arg_1, arg_2);
}

@vertex
fn vertex_main() -> @builtin(position) vec4<f32> {
  select_ed7c13();
  return vec4<f32>();
}

@fragment
fn fragment_main() {
  select_ed7c13();
}

@compute @workgroup_size(1)
fn compute_main() {
  select_ed7c13();
}
