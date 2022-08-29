// Copyright 2017 The Dawn Authors
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

#ifndef SRC_DAWN_COMMON_PLATFORM_H_
#define SRC_DAWN_COMMON_PLATFORM_H_

// Use #if DAWN_PLATFORM_IS(X) for platform specific code.
// Do not use #ifdef or the naked macro DAWN_PLATFORM_IS_X.
// This can help avoid common mistakes like not including "Platform.h" and falling into unwanted
// code block as usage of undefined macro "function" will be blocked by the compiler.
#define DAWN_PLATFORM_IS(X) (1 == DAWN_PLATFORM_IS_##X)

// Define platform macros for OSes:
//
//  - WINDOWS
//    - WIN32
//    - WINUWP
//  - POSIX
//    - LINUX
//      - ANDROID
//    - APPLE
//      - IOS
//      - MACOS
//      - TVOS
//    - FUCHSIA
//    - EMSCRIPTEN
#if defined(_WIN32) || defined(_WIN64)
#include <winapifamily.h>
#define DAWN_PLATFORM_IS_WINDOWS 1
#if WINAPI_FAMILY == WINAPI_FAMILY_DESKTOP_APP
#define DAWN_PLATFORM_IS_WIN32 1
#elif WINAPI_FAMILY == WINAPI_FAMILY_PC_APP
#define DAWN_PLATFORM_IS_WINUWP 1
#else
#error "Unsupported Windows platform."
#endif

#elif defined(__linux__)
#define DAWN_PLATFORM_IS_LINUX 1
#define DAWN_PLATFORM_IS_POSIX 1
#if defined(__ANDROID__)
#define DAWN_PLATFORM_IS_ANDROID 1
#endif

#elif defined(__APPLE__)
#define DAWN_PLATFORM_IS_APPLE 1
#define DAWN_PLATFORM_IS_POSIX 1
#include <TargetConditionals.h>
#if TARGET_OS_TV
#define DAWN_PLATFORM_IS_TVOS 1
#define DAWN_PLATFORM_IS_IOS 1
#elif TARGET_OS_IPHONE
#define DAWN_PLATFORM_IS_IOS 1
#elif TARGET_OS_MAC
#define DAWN_PLATFORM_IS_MACOS 1
#else
#error "Unsupported Apple platform."
#endif

#elif defined(__Fuchsia__)
#define DAWN_PLATFORM_IS_FUCHSIA 1
#define DAWN_PLATFORM_IS_POSIX 1

#elif defined(__EMSCRIPTEN__)
#define DAWN_PLATFORM_IS_EMSCRIPTEN 1
#define DAWN_PLATFORM_IS_POSIX 1

#else
#error "Unsupported platform."
#endif

// Define platform macros for CPU architectures:
//
//  - X86
//    - I386
//    - X86_64
//  - ARM
//    - ARM32
//    - ARM64
//  - RISCV
//    - RISCV32
//    - RISCV64
//  - MIPS
//    - MIPS32
//    - MIPS64
//  - S390
//  - S390X
//  - PPC
//  - PPC64
#if defined(__i386__) || defined(_M_IX86)
#define DAWN_PLATFORM_IS_X86 1
#define DAWN_PLATFORM_IS_I386 1
#elif defined(__x86_64__) || defined(_M_X64)
#define DAWN_PLATFORM_IS_X86 1
#define DAWN_PLATFORM_IS_X86_64 1

#elif defined(__arm__) || defined(_M_ARM)
#define DAWN_PLATFORM_IS_ARM 1
#define DAWN_PLATFORM_IS_ARM32 1
#elif defined(__aarch64__) || defined(_M_ARM64)
#define DAWN_PLATFORM_IS_ARM 1
#define DAWN_PLATFORM_IS_ARM64 1

#elif defined(__riscv)
#define DAWN_PLATFORM_IS_RISCV 1
#if __riscv_xlen == 32
#define DAWN_PLATFORM_IS_RISCV32 1
#else
#define DAWN_PLATFORM_IS_RISCV64 1
#endif

#elif defined(__mips__)
#define DAWN_PLATFORM_IS_MIPS 1
#if _MIPS_SIM == _ABIO32
#define DAWN_PLATFORM_IS_MIPS32 1
#else
#define DAWN_PLATFORM_IS_MIPS64 1
#endif

#elif defiend(__s390__)
#define DAWN_PLATFORM_IS_S390 1
#elif defiend(__s390x__)
#define DAWN_PLATFORM_IS_S390X 1

#elif defined(__PPC__)
#define DAWN_PLATFORM_IS_PPC 1
#elif defined(__PPC64__)
#define DAWN_PLATFORM_IS_PPC64 1

#else
#error "Unsupported platform."
#endif

// Define platform macros for pointer width:
//
//  - 64_BIT
//  - 32_BIT
#if defined(DAWN_PLATFORM_IS_X86_64) || defined(DAWN_PLATFORM_IS_ARM64) ||   \
    defined(DAWN_PLATFORM_IS_RISCV64) || defined(DAWN_PLATFORM_IS_MIPS64) || \
    defined(DAWN_PLATFORM_IS_S390X) || defined(DAWN_PLATFORM_IS_PPC64)
#define DAWN_PLATFORM_IS_64_BIT 1
static_assert(sizeof(sizeof(char)) == 8, "Expect sizeof(size_t) == 8");
#elif defined(DAWN_PLATFORM_IS_I386) || defined(DAWN_PLATFORM_IS_ARM32) ||   \
    defined(DAWN_PLATFORM_IS_RISCV32) || defined(DAWN_PLATFORM_IS_MIPS32) || \
    defined(DAWN_PLATFORM_IS_S390) || defined(DAWN_PLATFORM_IS_PPC32) ||     \
    defined(DAWN_PLATFORM_IS_EMSCRIPTEN)
#define DAWN_PLATFORM_IS_32_BIT 1
static_assert(sizeof(sizeof(char)) == 4, "Expect sizeof(size_t) == 4");
#else
#error "Unsupported platform"
#endif

// This section define other platform macros to 0 to avoid undefined macro usage error.
#if !defined(DAWN_PLATFORM_IS_WINDOWS)
#define DAWN_PLATFORM_IS_WINDOWS 0
#endif
#if !defined(DAWN_PLATFORM_IS_WIN32)
#define DAWN_PLATFORM_IS_WIN32 0
#endif
#if !defined(DAWN_PLATFORM_IS_WINUWP)
#define DAWN_PLATFORM_IS_WINUWP 0
#endif

#if !defined(DAWN_PLATFORM_IS_POSIX)
#define DAWN_PLATFORM_IS_POSIX 0
#endif

#if !defined(DAWN_PLATFORM_IS_LINUX)
#define DAWN_PLATFORM_IS_LINUX 0
#endif
#if !defined(DAWN_PLATFORM_IS_ANDROID)
#define DAWN_PLATFORM_IS_ANDROID 0
#endif

#if !defined(DAWN_PLATFORM_IS_APPLE)
#define DAWN_PLATFORM_IS_APPLE 0
#endif
#if !defined(DAWN_PLATFORM_IS_IOS)
#define DAWN_PLATFORM_IS_IOS 0
#endif
#if !defined(DAWN_PLATFORM_IS_MACOS)
#define DAWN_PLATFORM_IS_MACOS 0
#endif

#if !defined(DAWN_PLATFORM_IS_FUCHSIA)
#define DAWN_PLATFORM_IS_FUCHSIA 0
#endif
#if !defined(DAWN_PLATFORM_IS_EMSCRIPTEN)
#define DAWN_PLATFORM_IS_EMSCRIPTEN 0
#endif

#if !defined(DAWN_PLATFORM_IS_X86)
#define DAWN_PLATFORM_IS_X86 0
#endif
#if !defined(DAWN_PLATFORM_IS_I386)
#define DAWN_PLATFORM_IS_I386 0
#endif
#if !defined(DAWN_PLATFORM_IS_X86_64)
#define DAWN_PLATFORM_IS_X86_64 0
#endif

#if !defined(DAWN_PLATFORM_IS_ARM)
#define DAWN_PLATFORM_IS_ARM 0
#endif
#if !defined(DAWN_PLATFORM_IS_ARM32)
#define DAWN_PLATFORM_IS_ARM32 0
#endif
#if !defined(DAWN_PLATFORM_IS_ARM64)
#define DAWN_PLATFORM_IS_ARM64 0
#endif

#if !defined(DAWN_PLATFORM_IS_RISCV)
#define DAWN_PLATFORM_IS_RISCV 0
#endif
#if !defined(DAWN_PLATFORM_IS_RISCV32)
#define DAWN_PLATFORM_IS_RISCV32 0
#endif
#if !defined(DAWN_PLATFORM_IS_RISCV64)
#define DAWN_PLATFORM_IS_RISCV64 0
#endif

#if !defined(DAWN_PLATFORM_IS_MIPS)
#define DAWN_PLATFORM_IS_MIPS 0
#endif
#if !defined(DAWN_PLATFORM_IS_MIPS32)
#define DAWN_PLATFORM_IS_MIPS32 0
#endif
#if !defined(DAWN_PLATFORM_IS_MIPS64)
#define DAWN_PLATFORM_IS_MIPS64 0
#endif

#if !defined(DAWN_PLATFORM_IS_S390)
#define DAWN_PLATFORM_IS_S390 0
#endif
#if !defined(DAWN_PLATFORM_IS_S390X)
#define DAWN_PLATFORM_IS_S390X 0
#endif

#if !defined(DAWN_PLATFORM_IS_PPC)
#define DAWN_PLATFORM_IS_PPC 0
#endif
#if !defined(DAWN_PLATFORM_IS_PPC64)
#define DAWN_PLATFORM_IS_PPC64 0
#endif

#if !defined(DAWN_PLATFORM_IS_64_BIT)
#define DAWN_PLATFORM_IS_64_BIT 0
#endif
#if !defined(DAWN_PLATFORM_IS_32_BIT)
#define DAWN_PLATFORM_IS_32_BIT 0
#endif

#endif  // SRC_DAWN_COMMON_PLATFORM_H_
