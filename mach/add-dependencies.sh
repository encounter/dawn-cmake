#!/usr/bin/env bash
set -exuo pipefail

echo "Note: You should run gclient sync before this script"

# Remove unneeded dependencies
rm -rf build
rm -rf buildtools
rm -rf testing
rm -rf third_party/angle
rm -rf third_party/benchmark
rm -rf third_party/catapult
rm -rf third_party/googletest
rm -rf third_party/gpuweb-cts
rm -rf third_party/llvm-build
rm -rf third_party/markupsafe
rm -rf third_party/protobuf
rm -rf third_party/swiftshader
rm -rf third_party/vulkan_memory_allocator
rm -rf third_party/vulkan-deps/glslang
rm -rf third_party/vulkan-deps/spirv-cross
rm -rf third_party/vulkan-deps/vulkan-loader
rm -rf third_party/vulkan-deps/vulkan-validation-layers
rm -rf third_party/webgpu-cts
rm -rf third_party/zlib

# Ensure vulkan-deps are committed
rm -f third_party/vulkan-deps/.gitignore

# Remove gitmodules, some third_party/ repositories contain these and leaving them around would
# cause any recursive submodule clones to fail because e.g. some reference internal Google
# repositories. We don't want them anyway.
find third_party -type f -name .gitmodules -delete

# Turn subrepositories into regular folders.
find third_party -depth -type d -name .git -exec rm -rf {} \;

# Remove files that are not needed.
find third_party -depth -type d -name tests -print -exec rm -rf {} \;
find third_party -depth -type d -name docs -print -exec rm -rf {} \;
find third_party -depth -type d -name samples -print -exec rm -rf {} \;
rm -rf third_party/swiftshader/third_party/SPIRV-Tools # already in third_party/vulkan-deps/spirv-tools
rm -rf third_party/swiftshader/third_party/SPIRV-Headers # already in third_party/vulkan-deps/spirv-headers

git add third_party/
echo "you may now 'git commit -s -m 'update dependencies' if you are happy with the staged changes"
