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

#include <utility>

#include "dawn/common/Math.h"
#include "dawn/native/Blob.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace dawn::native {
namespace {

// Test that a blob starts empty.
TEST(BlobTests, DefaultEmpty) {
    Blob b;
    EXPECT_TRUE(b.Empty());
    EXPECT_EQ(b.Data(), nullptr);
    EXPECT_EQ(b.Size(), 0u);
}

// Test that you can create a blob with a size in bytes and write/read its contents.
TEST(BlobTests, SizedCreation) {
    Blob b = CreateBlob(10);
    EXPECT_FALSE(b.Empty());
    EXPECT_EQ(b.Size(), 10u);
    ASSERT_NE(b.Data(), nullptr);
    // We should be able to copy 10 bytes into the blob.
    char data[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    memcpy(b.Data(), data, sizeof(data));
    // And retrieve the exact contents back.
    EXPECT_EQ(memcmp(b.Data(), data, sizeof(data)), 0);
}

// Test that you can create a zero-sized blob.
TEST(BlobTests, EmptySizedCreation) {
    Blob b = CreateBlob(0);
    EXPECT_TRUE(b.Empty());
    EXPECT_EQ(b.Data(), nullptr);
    EXPECT_EQ(b.Size(), 0u);
}

// Test that you can create a blob with UnsafeCreateWithDeleter, and the deleter is
// called on destruction.
TEST(BlobTests, UnsafeCreateWithDeleter) {
    unsigned char data[13] = "hello world!";
    testing::StrictMock<testing::MockFunction<void()>> mockDeleter;
    {
        // Make a blob with a mock deleter.
        Blob b = Blob::UnsafeCreateWithDeleter(data, sizeof(data), [&]() { mockDeleter.Call(); });
        // Check the contents.
        EXPECT_FALSE(b.Empty());
        EXPECT_EQ(b.Size(), sizeof(data));
        ASSERT_EQ(b.Data(), data);
        EXPECT_EQ(memcmp(b.Data(), data, sizeof(data)), 0);

        // |b| is deleted when this scope exits.
        EXPECT_CALL(mockDeleter, Call());
    }
}

// Test that you can create a blob with UnsafeCreateWithDeleter with zero size but non-null data.
// The deleter is still called on destruction, and the blob is normalized to be empty.
TEST(BlobTests, UnsafeCreateWithDeleterZeroSize) {
    unsigned char data[13] = "hello world!";
    testing::StrictMock<testing::MockFunction<void()>> mockDeleter;
    {
        // Make a blob with a mock deleter.
        Blob b = Blob::UnsafeCreateWithDeleter(data, 0, [&]() { mockDeleter.Call(); });
        // Check the contents.
        EXPECT_TRUE(b.Empty());
        EXPECT_EQ(b.Size(), 0u);
        // Data still points to the data.
        EXPECT_EQ(b.Data(), data);

        // |b| is deleted when this scope exits.
        EXPECT_CALL(mockDeleter, Call());
    }
}

// Test that you can create a blob with UnsafeCreateWithDeleter that points to nothing.
// The deleter should still be called.
TEST(BlobTests, UnsafeCreateWithDeleterEmpty) {
    testing::StrictMock<testing::MockFunction<void()>> mockDeleter;
    {
        // Make a blob with a mock deleter.
        Blob b = Blob::UnsafeCreateWithDeleter(nullptr, 0, [&]() { mockDeleter.Call(); });
        // Check the contents.
        EXPECT_TRUE(b.Empty());
        EXPECT_EQ(b.Size(), 0u);
        EXPECT_EQ(b.Data(), nullptr);

        // |b| is deleted when this scope exits.
        EXPECT_CALL(mockDeleter, Call());
    }
}

// Test that move construction moves the data from one blob into the new one.
TEST(BlobTests, MoveConstruct) {
    // Create the blob.
    Blob b1 = CreateBlob(10);
    char data[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    memcpy(b1.Data(), data, sizeof(data));

    // Move construct b2 from b1.
    Blob b2(std::move(b1));

    // Data should be moved.
    EXPECT_FALSE(b2.Empty());
    EXPECT_EQ(b2.Size(), 10u);
    ASSERT_NE(b2.Data(), nullptr);
    EXPECT_EQ(memcmp(b2.Data(), data, sizeof(data)), 0);
}

// Test that move assignment moves the data from one blob into another.
TEST(BlobTests, MoveAssign) {
    // Create the blob.
    Blob b1 = CreateBlob(10);
    char data[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    memcpy(b1.Data(), data, sizeof(data));

    // Move assign b2 from b1.
    Blob b2;
    b2 = std::move(b1);

    // Data should be moved.
    EXPECT_FALSE(b2.Empty());
    EXPECT_EQ(b2.Size(), 10u);
    ASSERT_NE(b2.Data(), nullptr);
    EXPECT_EQ(memcmp(b2.Data(), data, sizeof(data)), 0);
}

// Test that move assignment can replace the contents of the moved-to blob.
TEST(BlobTests, MoveAssignOver) {
    // Create the blob.
    Blob b1 = CreateBlob(10);
    char data[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    memcpy(b1.Data(), data, sizeof(data));

    // Create another blob with a mock deleter.
    testing::StrictMock<testing::MockFunction<void()>> mockDeleter;
    Blob b2 = Blob::UnsafeCreateWithDeleter(nullptr, 0, [&]() { mockDeleter.Call(); });

    // Move b1 into b2, replacing b2's contents, and expect the deleter to be called.
    EXPECT_CALL(mockDeleter, Call());
    b2 = std::move(b1);

    // Data should be moved.
    EXPECT_FALSE(b2.Empty());
    EXPECT_EQ(b2.Size(), 10u);
    ASSERT_NE(b2.Data(), nullptr);
    EXPECT_EQ(memcmp(b2.Data(), data, sizeof(data)), 0);
}

// Test that an empty blob can be requested to have a particular alignment.
TEST(BlobTests, EmptyAlignTo) {
    for (size_t alignment : {1, 2, 4, 8, 16, 32}) {
        Blob b;
        EXPECT_TRUE(b.Empty());
        EXPECT_EQ(b.Size(), 0u);
        EXPECT_EQ(b.Data(), nullptr);
        b.AlignTo(alignment);
        // After aligning, it is still empty.
        EXPECT_TRUE(b.Empty());
        EXPECT_EQ(b.Size(), 0u);
        EXPECT_EQ(b.Data(), nullptr);
    }
}

// Test that AlignTo makes a blob have a particular alignment.
TEST(BlobTests, AlignTo) {
    uint8_t data[64];
    for (uint8_t i = 0; i < sizeof(data); ++i) {
        data[i] = i;
    }
    // Test multiple alignments.
    for (size_t alignment : {1, 2, 4, 8, 16, 32}) {
        for (size_t offset = 0; offset < alignment; ++offset) {
            // Make a blob pointing to |data| starting at |offset|.
            size_t size = sizeof(data) - offset;
            testing::StrictMock<testing::MockFunction<void()>> mockDeleter;
            Blob b =
                Blob::UnsafeCreateWithDeleter(&data[offset], size, [&]() { mockDeleter.Call(); });
            bool alreadyAligned = IsPtrAligned(&data[offset], alignment);

            // The backing store should be deleted at the end of the scope, or because it was
            // replaced.
            EXPECT_CALL(mockDeleter, Call());

            b.AlignTo(alignment);
            if (!alreadyAligned) {
                // If the Blob is not aligned, its data will be deleted and replaced by AlignTo.
                testing::Mock::VerifyAndClearExpectations(&mockDeleter);
            }
            // The blob should not have changed in size.
            EXPECT_EQ(b.Size(), size) << "alignment = " << alignment << " offset = " << offset;
            // The data should be aligned.
            EXPECT_TRUE(IsPtrAligned(b.Data(), alignment))
                << "alignment = " << alignment << " offset = " << offset;
            // The contents should be the same.
            EXPECT_EQ(memcmp(b.Data(), &data[offset], size), 0)
                << "alignment = " << alignment << " offset = " << offset;
            // If the data was already aligned, the blob should point to the same memory.
            EXPECT_EQ(alreadyAligned, b.Data() == &data[offset])
                << "alignment = " << alignment << " offset = " << offset;
        }
    }
}

}  // namespace
}  // namespace dawn::native
