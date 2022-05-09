var<workgroup> a : i32;
var<workgroup> b : i32;
var<workgroup> c : i32; // unused

fn uses_a() {
  a = a + 1;
}

fn uses_b() {
  b = b * 2;
}

fn uses_a_and_b() {
  b = a;
}

fn no_uses() {
}

fn outer() {
  a = 0;
  uses_a();
  uses_a_and_b();
  uses_b();
  no_uses();
}

@stage(compute) @workgroup_size(1)
fn main1() {
  a = 42;
  uses_a();
}

@stage(compute) @workgroup_size(1)
fn main2() {
  b = 7;
  uses_b();
}

@stage(compute) @workgroup_size(1)
fn main3() {
  outer();
  no_uses();
}

@stage(compute) @workgroup_size(1)
fn main4() {
  no_uses();
}
