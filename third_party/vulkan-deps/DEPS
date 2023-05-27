# This file is used to manage Vulkan dependencies for several repos. It is
# used by gclient to determine what version of each dependency to check out, and
# where.

# Avoids the need for a custom root variable.
use_relative_paths = True

vars = {
  'chromium_git': 'https://chromium.googlesource.com',

  # Current revision of glslang, the Khronos SPIRV compiler.
  'glslang_revision': '9fbc561947f6b5275289a1985676fb7267273e09',

  # Current revision of spirv-cross, the Khronos SPIRV cross compiler.
  'spirv_cross_revision': '12542fc6fc05000e04742daf93892a0b10edbe80',

  # Current revision fo the SPIRV-Headers Vulkan support library.
  'spirv_headers_revision': 'bdbfd019be6952fd8fa9bd5606a8798a7530c853',

  # Current revision of SPIRV-Tools for Vulkan.
  'spirv_tools_revision': 'e7c6084fd1d6d6f5ac393e842728d8be309688ca',

  # Current revision of Khronos Vulkan-Headers.
  'vulkan_headers_revision': '9e61870ecbd32514113b467e0a0c46f60ed222c7',

  # Current revision of Khronos Vulkan-Loader.
  'vulkan_loader_revision': 'b95d065ec567f862ab5baa85ab99ecb1f8979fbc',

  # Current revision of Khronos Vulkan-Tools.
  'vulkan_tools_revision': 'f31c10971f7cca67ecb4eb2b1959ebabfa38470b',

  # Current revision of Khronos Vulkan-ValidationLayers.
  'vulkan_validation_revision': '05fc0fd4fb402e6f1191696bedc60a867fd6b5aa',
}

deps = {
  'glslang/src': {
    'url': '{chromium_git}/external/github.com/KhronosGroup/glslang@{glslang_revision}',
  },

  'spirv-cross/src': {
    'url': '{chromium_git}/external/github.com/KhronosGroup/SPIRV-Cross@{spirv_cross_revision}',
  },

  'spirv-headers/src': {
    'url': '{chromium_git}/external/github.com/KhronosGroup/SPIRV-Headers@{spirv_headers_revision}',
  },

  'spirv-tools/src': {
    'url': '{chromium_git}/external/github.com/KhronosGroup/SPIRV-Tools@{spirv_tools_revision}',
  },

  'vulkan-headers/src': {
    'url': '{chromium_git}/external/github.com/KhronosGroup/Vulkan-Headers@{vulkan_headers_revision}',
  },

  'vulkan-loader/src': {
    'url': '{chromium_git}/external/github.com/KhronosGroup/Vulkan-Loader@{vulkan_loader_revision}',
  },

  'vulkan-tools/src': {
    'url': '{chromium_git}/external/github.com/KhronosGroup/Vulkan-Tools@{vulkan_tools_revision}',
  },

  'vulkan-validation-layers/src': {
    'url': '{chromium_git}/external/github.com/KhronosGroup/Vulkan-ValidationLayers@{vulkan_validation_revision}',
  },
}
