# This file is used to manage Vulkan dependencies for several repos. It is
# used by gclient to determine what version of each dependency to check out, and
# where.

# Avoids the need for a custom root variable.
use_relative_paths = True

vars = {
  'chromium_git': 'https://chromium.googlesource.com',

  # Current revision of glslang, the Khronos SPIRV compiler.
  'glslang_revision': '9e78bc8108a13d4d4ed860b2c5547092059ed83e',

  # Current revision of spirv-cross, the Khronos SPIRV cross compiler.
  'spirv_cross_revision': 'c93ee9261ed38be0b37b7cc40e2c5c47eaf5615d',

  # Current revision fo the SPIRV-Headers Vulkan support library.
  'spirv_headers_revision': '93754d52d6cbbfd61f4e87571079e8a28e65f8ca',

  # Current revision of SPIRV-Tools for Vulkan.
  'spirv_tools_revision': '66bdbacc9ca9694aef2846a56b953e296aa9cbd5',

  # Current revision of Khronos Vulkan-Headers.
  'vulkan_headers_revision': '715673702f5b18ffb8e5832e67cf731468d32ac6',

  # Current revision of Khronos Vulkan-Loader.
  'vulkan_loader_revision': '40faec799ce6b17f46f4bf28ce81782a1bafbbb0',

  # Current revision of Khronos Vulkan-Tools.
  'vulkan_tools_revision': '439026106ac98679e5961a499790327a8bf8f1d6',

  # Current revision of Khronos Vulkan-ValidationLayers.
  'vulkan_validation_revision': '1396d7b36ae467d87983e6a73cacaf2ab87ca37e',
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
