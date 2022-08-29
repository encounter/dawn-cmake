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

#ifndef SRC_TINT_WRITER_GLSL_GENERATOR_H_
#define SRC_TINT_WRITER_GLSL_GENERATOR_H_

#include <memory>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "src/tint/ast/access.h"
#include "src/tint/ast/pipeline_stage.h"
#include "src/tint/sem/binding_point.h"
#include "src/tint/sem/sampler_texture_pair.h"
#include "src/tint/writer/glsl/version.h"
#include "src/tint/writer/text.h"

// Forward declarations
namespace tint {
class Program;
}  // namespace tint

namespace tint::writer::glsl {

using BindingMap = std::unordered_map<sem::SamplerTexturePair, std::string>;

/// Configuration options used for generating GLSL.
struct Options {
    /// Constructor
    Options();

    /// Destructor
    ~Options();

    /// Copy constructor
    Options(const Options&);

    /// A map of SamplerTexturePair to combined sampler names for the
    /// CombineSamplers transform
    BindingMap binding_map;

    /// The binding point to use for placeholder samplers.
    sem::BindingPoint placeholder_binding_point;

    /// A map of old binding point to new binding point for the BindingRemapper
    /// transform
    std::unordered_map<sem::BindingPoint, sem::BindingPoint> binding_points;

    /// A map of old binding point to new access control for the BindingRemapper
    /// transform
    std::unordered_map<sem::BindingPoint, ast::Access> access_controls;

    /// If true, then validation will be disabled for binding point collisions
    /// generated by the BindingRemapper transform
    bool allow_collisions = false;

    /// Set to `true` to disable workgroup memory zero initialization
    bool disable_workgroup_init = false;

    /// Set to 'true' to generates binding mappings for external textures
    bool generate_external_texture_bindings = false;

    /// The GLSL version to emit
    Version version;
};

/// The result produced when generating GLSL.
struct Result {
    /// Constructor
    Result();

    /// Destructor
    ~Result();

    /// Copy constructor
    Result(const Result&);

    /// True if generation was successful.
    bool success = false;

    /// The errors generated during code generation, if any.
    std::string error;

    /// The generated GLSL.
    std::string glsl = "";

    /// The list of entry points in the generated GLSL.
    std::vector<std::pair<std::string, ast::PipelineStage>> entry_points;
};

/// Generate GLSL for a program, according to a set of configuration options.
/// The result will contain the GLSL, as well as success status and diagnostic
/// information.
/// @param program the program to translate to GLSL
/// @param options the configuration options to use when generating GLSL
/// @param entry_point the entry point to generate GLSL for
/// @returns the resulting GLSL and supplementary information
Result Generate(const Program* program, const Options& options, const std::string& entry_point);

}  // namespace tint::writer::glsl

#endif  // SRC_TINT_WRITER_GLSL_GENERATOR_H_
