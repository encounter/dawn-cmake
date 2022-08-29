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


// fn atan2(vec<3, fa>, vec<3, fa>) -> vec<3, fa>
fn atan2_3c2865() {
  const arg_0 = vec3(1);
  const arg_1 = vec3(1);
  var res = atan2(arg_0, arg_1);
}

@vertex
fn vertex_main() -> @builtin(position) vec4<f32> {
  atan2_3c2865();
  return vec4<f32>();
}

@fragment
fn fragment_main() {
  atan2_3c2865();
}

@compute @workgroup_size(1)
fn compute_main() {
  atan2_3c2865();
}
