#include "catch.hpp"

#include "utils_test.hpp"

#include "repeat.h"
#include "stream/input/input_stream_type.h"

#include <format>
#include <vector>

#define TEST_DEFAULT_TAG "[stream][input][input_stream_type]"
CATCH_REGISTER_TAG_ALIAS("[@input_stream_type]", TEST_DEFAULT_TAG)

static uint8_t ReadU8(StreamType *is);

static const std::vector<uint8_t> g_buffer_test =
    std::vector<uint8_t>{0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                         0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};

TEST_CASE("is_type_read_u8 must return a uint8_t correctly from stream",
          TEST_DEFAULT_TAG "[is_type_read_u8]")
{
    StreamType is = StreamType{.offset = 0, .size = g_buffer_test.size()};

    for (uint8_t expected_value : g_buffer_test)
    {
        CHECK(is_type_read_u8(&is, ReadU8) == expected_value);
    }
}

TEST_CASE("is_type_read_u16 must return a uint8_t correctly from stream",
          TEST_DEFAULT_TAG "[is_type_read_u16]")
{
    StreamType is = StreamType{.offset = 0, .size = g_buffer_test.size()};

    for (size_t i = 0; i < g_buffer_test.size(); i += sizeof(uint16_t))
    {
        const uint16_t expected_value =
            ((static_cast<uint16_t>(g_buffer_test.at(i)) << 8) |
             (static_cast<uint16_t>(g_buffer_test.at(i + 1))));
        CHECK(is_type_read_u16(&is, ReadU8) == expected_value);
    }
}

TEST_CASE("is_type_read_u32 must return a uint8_t correctly from stream",
          TEST_DEFAULT_TAG "[is_type_read_u32]")
{
    StreamType is = StreamType{.offset = 0, .size = g_buffer_test.size()};

    for (size_t i = 0; i < g_buffer_test.size(); i += sizeof(uint32_t))
    {
        const uint32_t expected_value =
            ((static_cast<uint32_t>(g_buffer_test.at(i)) << 24) |
             (static_cast<uint32_t>(g_buffer_test.at(i + 1)) << 16) |
             (static_cast<uint32_t>(g_buffer_test.at(i + 2)) << 8) |
             (static_cast<uint32_t>(g_buffer_test.at(i + 3))));
        CHECK(is_type_read_u32(&is, ReadU8) == expected_value);
    }
}

TEST_CASE("is_type_read_u64 must return a uint8_t correctly from stream",
          TEST_DEFAULT_TAG "[is_type_read_u64]")
{
    StreamType is = StreamType{.offset = 0, .size = g_buffer_test.size()};

    for (size_t i = 0; i < g_buffer_test.size(); i += sizeof(uint64_t))
    {
        const uint64_t expected_value =
            ((static_cast<uint64_t>(g_buffer_test.at(i)) << 56) |
             (static_cast<uint64_t>(g_buffer_test.at(i + 1)) << 48) |
             (static_cast<uint64_t>(g_buffer_test.at(i + 2)) << 40) |
             (static_cast<uint64_t>(g_buffer_test.at(i + 3)) << 32) |
             (static_cast<uint64_t>(g_buffer_test.at(i + 4)) << 24) |
             (static_cast<uint64_t>(g_buffer_test.at(i + 5)) << 16) |
             (static_cast<uint64_t>(g_buffer_test.at(i + 6)) << 8) |
             (static_cast<uint64_t>(g_buffer_test.at(i + 7))));
        CHECK(is_type_read_u64(&is, ReadU8) == expected_value);
    }
}

static uint8_t ReadU8(StreamType *is)
{
    return g_buffer_test.at(is->offset++);
}