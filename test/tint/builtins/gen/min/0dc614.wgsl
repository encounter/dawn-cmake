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
// File generated by tools/intrinsic-gen
// using the template:
//   test/tint/builtins/builtins.wgsl.tmpl
// and the intrinsic defintion file:
//   src/tint/intrinsics.def
//
// Do not modify this file directly
////////////////////////////////////////////////////////////////////////////////


// fn min(vec<4, u32>, vec<4, u32>) -> vec<4, u32>
fn min_0dc614() {
  var res: vec4<u32> = min(vec4<u32>(), vec4<u32>());
}

@stage(vertex)
fn vertex_main() -> @builtin(position) vec4<f32> {
  min_0dc614();
  return vec4<f32>();
}

@stage(fragment)
fn fragment_main() {
  min_0dc614();
}

@stage(compute) @workgroup_size(1)
fn compute_main() {
  min_0dc614();
}