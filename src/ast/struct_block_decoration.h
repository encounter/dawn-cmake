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

#ifndef SRC_AST_STRUCT_BLOCK_DECORATION_H_
#define SRC_AST_STRUCT_BLOCK_DECORATION_H_

#include <memory>
#include <ostream>
#include <vector>

#include "src/ast/struct_decoration.h"

namespace tint {
namespace ast {

/// The struct decorations
class StructBlockDecoration
    : public Castable<StructBlockDecoration, StructDecoration> {
 public:
  /// constructor
  /// @param source the source of this decoration
  explicit StructBlockDecoration(const Source& source);
  ~StructBlockDecoration() override;

  /// @returns true if this is a block struct
  bool IsBlock() const override;

  /// Outputs the decoration to the given stream
  /// @param out the stream to write to
  /// @param indent number of spaces to indent the node when writing
  void to_str(std::ostream& out, size_t indent) const override;
};

/// List of struct decorations
using StructDecorationList = std::vector<StructDecoration*>;

}  // namespace ast
}  // namespace tint

#endif  // SRC_AST_STRUCT_BLOCK_DECORATION_H_
