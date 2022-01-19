#include "catch.hpp"

#include "utils_test.hpp"

#include "stream/stream_type.h"

#include <format>

#define TEST_DEFAULT_TAG "[stream][stream_type]"
CATCH_REGISTER_TAG_ALIAS("[@stream_type]", TEST_DEFAULT_TAG)

TEST_CASE("stream_type_make must creat StreamType correctly",
          TEST_DEFAULT_TAG "[stream_type_make]")
{
    const size_t size = GENERATE(as<size_t>{}, 0, SIZE_MAX);
    const StreamType stream_expected = StreamType{.offset = 0, .size = size};
    const StreamType stream_made = stream_type_make(size);

    INFO(std::format("With size = {}", size))

    REQUIRE(stream_made == stream_expected);
}

TEST_CASE("stream_type_shift_right must change offset correctly",
          TEST_DEFAULT_TAG "[stream_type_shift_right]")
{
    constexpr size_t size_default = 7;

    StreamType stream = StreamType{.offset = 0, .size = size_default};

    SECTION("When shift size is lower than available space")
    {
        const size_t shift_size = GENERATE(range((size_t)0, size_default));

        INFO(std::format("With shift_size = {}", shift_size))

        stream_type_shift_right(&stream, shift_size);
        REQUIRE(stream.offset == shift_size);
    }

    SECTION("When shift size is equals to available space")
    {
        stream_type_shift_right(&stream, size_default);
        REQUIRE(stream.offset == size_default);
    }

    SECTION("When shift size is higher than available space")
    {
        const size_t shift_size = GENERATE((size_default + 1), SIZE_MAX);

        INFO(std::format("With shift_size = {}", shift_size))

        stream_type_shift_right(&stream, shift_size);
        REQUIRE(stream.offset == size_default);
    }
}

TEST_CASE("stream_type_shift_left must change offset correctly",
          TEST_DEFAULT_TAG "[stream_type_shift_left]")
{
    constexpr size_t size_default = 7;

    StreamType stream =
        StreamType{.offset = size_default, .size = size_default};

    SECTION("When shift size is lower than offset")
    {
        const size_t shift_size = GENERATE(range((size_t)0, size_default));

        INFO(std::format("With shift_size = {}", shift_size))

        stream_type_shift_left(&stream, shift_size);
        REQUIRE(stream.offset == (size_default - shift_size));
    }

    SECTION("When shift size is equals to offset")
    {
        stream_type_shift_left(&stream, size_default);
        REQUIRE(stream.offset == 0);
    }

    SECTION("When shift size is higher than offset")
    {
        const size_t shift_size = GENERATE((size_default + 1), SIZE_MAX);

        INFO(std::format("With shift_size = {}", shift_size))

        stream_type_shift_left(&stream, shift_size);
        REQUIRE(stream.offset == 0);
    }
}
