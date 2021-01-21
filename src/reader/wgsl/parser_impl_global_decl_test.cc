// Copyright 2020 The Tint Authors.
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

#include "gtest/gtest.h"
#include "src/reader/wgsl/parser_impl.h"
#include "src/reader/wgsl/parser_impl_test_helper.h"
#include "src/type/array_type.h"
#include "src/type/struct_type.h"

namespace tint {
namespace reader {
namespace wgsl {
namespace {

TEST_F(ParserImplTest, GlobalDecl_Semicolon) {
  auto p = parser(";");
  p->expect_global_decl();
  ASSERT_FALSE(p->has_error()) << p->error();
}

TEST_F(ParserImplTest, GlobalDecl_GlobalVariable) {
  auto p = parser("var<out> a : vec2<i32> = vec2<i32>(1, 2);");
  p->expect_global_decl();
  ASSERT_FALSE(p->has_error()) << p->error();

  auto& m = p->get_module();
  ASSERT_EQ(m.global_variables().size(), 1u);

  auto* v = m.global_variables()[0];
  EXPECT_EQ(v->symbol(), p->get_module().RegisterSymbol("a"));
}

TEST_F(ParserImplTest, GlobalDecl_GlobalVariable_Invalid) {
  auto p = parser("var<out> a : vec2<invalid>;");
  p->expect_global_decl();
  ASSERT_TRUE(p->has_error());
  EXPECT_EQ(p->error(), "1:19: unknown constructed type 'invalid'");
}

TEST_F(ParserImplTest, GlobalDecl_GlobalVariable_MissingSemicolon) {
  auto p = parser("var<out> a : vec2<i32>");
  p->expect_global_decl();
  ASSERT_TRUE(p->has_error());
  EXPECT_EQ(p->error(), "1:23: expected ';' for variable declaration");
}

TEST_F(ParserImplTest, GlobalDecl_GlobalConstant) {
  auto p = parser("const a : i32 = 2;");
  p->expect_global_decl();
  ASSERT_FALSE(p->has_error()) << p->error();

  auto& m = p->get_module();
  ASSERT_EQ(m.global_variables().size(), 1u);

  auto* v = m.global_variables()[0];
  EXPECT_EQ(v->symbol(), p->get_module().RegisterSymbol("a"));
}

TEST_F(ParserImplTest, GlobalDecl_GlobalConstant_Invalid) {
  auto p = parser("const a : vec2<i32>;");
  p->expect_global_decl();
  ASSERT_TRUE(p->has_error());
  EXPECT_EQ(p->error(), "1:20: expected '=' for constant declaration");
}

TEST_F(ParserImplTest, GlobalDecl_GlobalConstant_MissingSemicolon) {
  auto p = parser("const a : vec2<i32> = vec2<i32>(1, 2)");
  p->expect_global_decl();
  ASSERT_TRUE(p->has_error());
  EXPECT_EQ(p->error(), "1:38: expected ';' for constant declaration");
}

TEST_F(ParserImplTest, GlobalDecl_TypeAlias) {
  auto p = parser("type A = i32;");
  p->expect_global_decl();
  ASSERT_FALSE(p->has_error()) << p->error();

  auto& m = p->get_module();
  ASSERT_EQ(m.constructed_types().size(), 1u);
  ASSERT_TRUE(m.constructed_types()[0]->Is<type::Alias>());
  EXPECT_EQ(
      m.SymbolToName(m.constructed_types()[0]->As<type::Alias>()->symbol()),
      "A");
}

TEST_F(ParserImplTest, GlobalDecl_TypeAlias_StructIdent) {
  auto p = parser(R"(struct A {
  a : f32;
};
type B = A;)");
  p->expect_global_decl();
  p->expect_global_decl();
  ASSERT_FALSE(p->has_error()) << p->error();

  auto& m = p->get_module();
  ASSERT_EQ(m.constructed_types().size(), 2u);
  ASSERT_TRUE(m.constructed_types()[0]->Is<type::Struct>());
  auto* str = m.constructed_types()[0]->As<type::Struct>();
  EXPECT_EQ(str->symbol(), p->get_module().RegisterSymbol("A"));

  ASSERT_TRUE(m.constructed_types()[1]->Is<type::Alias>());
  auto* alias = m.constructed_types()[1]->As<type::Alias>();
  EXPECT_EQ(alias->symbol(), p->get_module().RegisterSymbol("B"));
  EXPECT_EQ(alias->type(), str);
}

TEST_F(ParserImplTest, GlobalDecl_TypeAlias_Invalid) {
  auto p = parser("type A = invalid;");
  p->expect_global_decl();
  ASSERT_TRUE(p->has_error());
  EXPECT_EQ(p->error(), "1:10: unknown constructed type 'invalid'");
}

TEST_F(ParserImplTest, GlobalDecl_TypeAlias_MissingSemicolon) {
  auto p = parser("type A = i32");
  p->expect_global_decl();
  ASSERT_TRUE(p->has_error());
  EXPECT_EQ(p->error(), "1:13: expected ';' for type alias");
}

TEST_F(ParserImplTest, GlobalDecl_Function) {
  auto p = parser("fn main() -> void { return; }");
  p->expect_global_decl();
  ASSERT_FALSE(p->has_error()) << p->error();

  auto& m = p->get_module();
  ASSERT_EQ(m.Functions().size(), 1u);
  EXPECT_EQ(m.SymbolToName(m.Functions()[0]->symbol()), "main");
}

TEST_F(ParserImplTest, GlobalDecl_Function_WithDecoration) {
  auto p = parser("[[workgroup_size(2)]] fn main() -> void { return; }");
  p->expect_global_decl();
  ASSERT_FALSE(p->has_error()) << p->error();

  auto& m = p->get_module();
  ASSERT_EQ(m.Functions().size(), 1u);
  EXPECT_EQ(m.SymbolToName(m.Functions()[0]->symbol()), "main");
}

TEST_F(ParserImplTest, GlobalDecl_Function_Invalid) {
  auto p = parser("fn main() -> { return; }");
  p->expect_global_decl();
  ASSERT_TRUE(p->has_error());
  EXPECT_EQ(p->error(), "1:14: unable to determine function return type");
}

TEST_F(ParserImplTest, GlobalDecl_ParsesStruct) {
  auto p = parser("struct A { b: i32; c: f32;};");
  p->expect_global_decl();
  ASSERT_FALSE(p->has_error()) << p->error();

  auto& m = p->get_module();
  ASSERT_EQ(m.constructed_types().size(), 1u);

  auto* t = m.constructed_types()[0];
  ASSERT_NE(t, nullptr);
  ASSERT_TRUE(t->Is<type::Struct>());

  auto* str = t->As<type::Struct>();
  EXPECT_EQ(str->symbol(), p->get_module().RegisterSymbol("A"));
  EXPECT_EQ(str->impl()->members().size(), 2u);
}

TEST_F(ParserImplTest, GlobalDecl_Struct_WithStride) {
  auto p =
      parser("struct A { [[offset(0)]] data: [[stride(4)]] array<f32>; };");

  p->expect_global_decl();
  ASSERT_FALSE(p->has_error()) << p->error();

  auto& m = p->get_module();
  ASSERT_EQ(m.constructed_types().size(), 1u);

  auto* t = m.constructed_types()[0];
  ASSERT_NE(t, nullptr);
  ASSERT_TRUE(t->Is<type::Struct>());

  auto* str = t->As<type::Struct>();
  EXPECT_EQ(str->symbol(), p->get_module().RegisterSymbol("A"));
  EXPECT_EQ(str->impl()->members().size(), 1u);
  EXPECT_FALSE(str->IsBlockDecorated());

  const auto* ty = str->impl()->members()[0]->type();
  ASSERT_TRUE(ty->Is<type::Array>());
  const auto* arr = ty->As<type::Array>();
  EXPECT_TRUE(arr->has_array_stride());
  EXPECT_EQ(arr->array_stride(), 4u);
}

TEST_F(ParserImplTest, GlobalDecl_Struct_WithDecoration) {
  auto p = parser("[[block]] struct A { [[offset(0)]] data: f32; };");
  p->expect_global_decl();
  ASSERT_FALSE(p->has_error()) << p->error();

  auto& m = p->get_module();
  ASSERT_EQ(m.constructed_types().size(), 1u);

  auto* t = m.constructed_types()[0];
  ASSERT_NE(t, nullptr);
  ASSERT_TRUE(t->Is<type::Struct>());

  auto* str = t->As<type::Struct>();
  EXPECT_EQ(str->symbol(), p->get_module().RegisterSymbol("A"));
  EXPECT_EQ(str->impl()->members().size(), 1u);
  EXPECT_TRUE(str->IsBlockDecorated());
}

TEST_F(ParserImplTest, GlobalDecl_Struct_Invalid) {
  auto p = parser("[[block]] A {};");
  p->expect_global_decl();
  ASSERT_TRUE(p->has_error());
  EXPECT_EQ(p->error(), "1:11: expected declaration after decorations");
}

TEST_F(ParserImplTest, GlobalDecl_StructMissing_Semi) {
  auto p = parser("[[block]] struct A {}");
  p->expect_global_decl();
  ASSERT_TRUE(p->has_error());
  EXPECT_EQ(p->error(), "1:22: expected ';' for struct declaration");
}

}  // namespace
}  // namespace wgsl
}  // namespace reader
}  // namespace tint
