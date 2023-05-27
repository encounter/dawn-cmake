// Copyright 2021 The Tint Authors.
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


// fn select(vec<2, i32>, vec<2, i32>, bool) -> vec<2, i32>
fn select_bb447f() {
  var res: vec2<i32> = select(vec2<i32>(1i), vec2<i32>(1i), true);
  prevent_dce = res;
}
@group(2) @binding(0) var<storage, read_write> prevent_dce : vec2<i32>;

@vertex
fn vertex_main() -> @builtin(position) vec4<f32> {
  select_bb447f();
  return vec4<f32>();
}

@fragment
fn fragment_main() {
  select_bb447f();
}

@compute @workgroup_size(1)
fn compute_main() {
  select_bb447f();
}
