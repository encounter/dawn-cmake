// Copyright 2020 The Dawn Authors
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

#include "utils/TestUtils.h"

#include "common/Assert.h"
#include "common/Constants.h"
#include "common/Math.h"
#include "utils/TextureUtils.h"
#include "utils/WGPUHelpers.h"

#include <vector>

namespace utils {

    uint32_t GetMinimumBytesPerRow(wgpu::TextureFormat format, uint32_t width) {
        const uint32_t bytesPerBlock = utils::GetTexelBlockSizeInBytes(format);
        const uint32_t blockWidth = utils::GetTextureFormatBlockWidth(format);
        ASSERT(width % blockWidth == 0);
        return Align(bytesPerBlock * (width / blockWidth), kTextureBytesPerRowAlignment);
    }

    TextureDataCopyLayout GetTextureDataCopyLayoutForTextureAtLevel(
        wgpu::TextureFormat format,
        wgpu::Extent3D textureSizeAtLevel0,
        uint32_t mipmapLevel,
        wgpu::TextureDimension dimension,
        uint32_t rowsPerImage) {
        // Compressed texture formats not supported in this function yet.
        ASSERT(utils::GetTextureFormatBlockWidth(format) == 1);

        TextureDataCopyLayout layout;

        layout.mipSize = {std::max(textureSizeAtLevel0.width >> mipmapLevel, 1u),
                          std::max(textureSizeAtLevel0.height >> mipmapLevel, 1u),
                          textureSizeAtLevel0.depthOrArrayLayers};

        if (dimension == wgpu::TextureDimension::e3D) {
            layout.mipSize.depthOrArrayLayers =
                std::max(textureSizeAtLevel0.depthOrArrayLayers >> mipmapLevel, 1u);
        }

        layout.bytesPerRow = GetMinimumBytesPerRow(format, layout.mipSize.width);

        if (rowsPerImage == wgpu::kCopyStrideUndefined) {
            rowsPerImage = layout.mipSize.height;
        }
        layout.rowsPerImage = rowsPerImage;

        uint32_t appliedRowsPerImage = rowsPerImage > 0 ? rowsPerImage : layout.mipSize.height;
        layout.bytesPerImage = layout.bytesPerRow * appliedRowsPerImage;

        layout.byteLength =
            RequiredBytesInCopy(layout.bytesPerRow, appliedRowsPerImage, layout.mipSize, format);

        const uint32_t bytesPerTexel = utils::GetTexelBlockSizeInBytes(format);
        layout.texelBlocksPerRow = layout.bytesPerRow / bytesPerTexel;
        layout.texelBlocksPerImage = layout.bytesPerImage / bytesPerTexel;
        layout.texelBlockCount = layout.byteLength / bytesPerTexel;

        return layout;
    }

    uint64_t RequiredBytesInCopy(uint64_t bytesPerRow,
                                 uint64_t rowsPerImage,
                                 wgpu::Extent3D copyExtent,
                                 wgpu::TextureFormat textureFormat) {
        uint32_t blockSize = utils::GetTexelBlockSizeInBytes(textureFormat);
        uint32_t blockWidth = utils::GetTextureFormatBlockWidth(textureFormat);
        uint32_t blockHeight = utils::GetTextureFormatBlockHeight(textureFormat);
        ASSERT(copyExtent.width % blockWidth == 0);
        uint32_t widthInBlocks = copyExtent.width / blockWidth;
        ASSERT(copyExtent.height % blockHeight == 0);
        uint32_t heightInBlocks = copyExtent.height / blockHeight;
        return RequiredBytesInCopy(bytesPerRow, rowsPerImage, widthInBlocks, heightInBlocks,
                                   copyExtent.depthOrArrayLayers, blockSize);
    }

    uint64_t RequiredBytesInCopy(uint64_t bytesPerRow,
                                 uint64_t rowsPerImage,
                                 uint64_t widthInBlocks,
                                 uint64_t heightInBlocks,
                                 uint64_t depth,
                                 uint64_t bytesPerBlock) {
        if (depth == 0) {
            return 0;
        }

        uint64_t bytesPerImage = bytesPerRow * rowsPerImage;
        uint64_t requiredBytesInCopy = bytesPerImage * (depth - 1);
        if (heightInBlocks != 0) {
            uint64_t lastRowBytes = widthInBlocks * bytesPerBlock;
            uint64_t lastImageBytes = bytesPerRow * (heightInBlocks - 1) + lastRowBytes;
            requiredBytesInCopy += lastImageBytes;
        }
        return requiredBytesInCopy;
    }

    uint64_t GetTexelCountInCopyRegion(uint64_t bytesPerRow,
                                       uint64_t rowsPerImage,
                                       wgpu::Extent3D copyExtent,
                                       wgpu::TextureFormat textureFormat) {
        return RequiredBytesInCopy(bytesPerRow, rowsPerImage, copyExtent, textureFormat) /
               utils::GetTexelBlockSizeInBytes(textureFormat);
    }

    void UnalignDynamicUploader(wgpu::Device device) {
        std::vector<uint8_t> data = {1};

        wgpu::TextureDescriptor descriptor = {};
        descriptor.size = {1, 1, 1};
        descriptor.format = wgpu::TextureFormat::R8Unorm;
        descriptor.usage = wgpu::TextureUsage::CopyDst | wgpu::TextureUsage::CopySrc;
        wgpu::Texture texture = device.CreateTexture(&descriptor);

        wgpu::ImageCopyTexture imageCopyTexture =
            utils::CreateImageCopyTexture(texture, 0, {0, 0, 0});
        wgpu::TextureDataLayout textureDataLayout =
            utils::CreateTextureDataLayout(0, wgpu::kCopyStrideUndefined);
        wgpu::Extent3D copyExtent = {1, 1, 1};

        // WriteTexture with exactly 1 byte of data.
        device.GetQueue().WriteTexture(&imageCopyTexture, data.data(), 1, &textureDataLayout,
                                       &copyExtent);
    }
}  // namespace utils
