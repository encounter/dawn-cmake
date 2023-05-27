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


// fn atanh(fa) -> fa
fn atanh_c5dc32() {
  var res = atanh(0.5);
}
@vertex
fn vertex_main() -> @builtin(position) vec4<f32> {
  atanh_c5dc32();
  return vec4<f32>();
}

@fragment
fn fragment_main() {
  atanh_c5dc32();
}

@compute @workgroup_size(1)
fn compute_main() {
  atanh_c5dc32();
}
