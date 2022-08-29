// Copyright 2022 The Dawn Authors
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

#ifndef SRC_DAWN_NATIVE_OPENGL_CONTEXTEXTERNAL_H_
#define SRC_DAWN_NATIVE_OPENGL_CONTEXTEXTERNAL_H_

#include <memory>

#include "dawn/native/opengl/DeviceGL.h"

namespace dawn::native::opengl {

class ContextExternal : public Device::Context {
  public:
    static ResultOrError<std::unique_ptr<ContextExternal>> Create(void (*makeCurrent)(void*),
                                                                  void (*destroy)(void*),
                                                                  void* userData);
    void MakeCurrent() override;
    ~ContextExternal() override;

  private:
    ContextExternal(void (*makeCurrent)(void*), void (*destroy)(void*), void* userData)
        : mMakeCurrent(makeCurrent), mDestroy(destroy), mUserData(userData) {}

    void (*mMakeCurrent)(void*);
    void (*mDestroy)(void*);
    void* mUserData;
};

}  // namespace dawn::native::opengl

#endif  // SRC_DAWN_NATIVE_OPENGL_CONTEXTEXTERNAL_H_
