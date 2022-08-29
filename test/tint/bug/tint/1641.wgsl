struct Normals {
  f : vec3<f32>,
}
const faceNormals = array<Normals, 1>(
  Normals(vec3(0, 0, 1)),
);

@vertex
fn main() -> @builtin(position) vec4<f32> {
  return vec4(faceNormals[0].f, 1.);
}
