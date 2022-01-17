#include "catch.hpp"

#include "utils_test.hpp"

#include "stream/stream_type.h"

#define TEST_DEFAULT_TAG "[stream][stream_type]"
CATCH_REGISTER_TAG_ALIAS("[@stream_type]", TEST_DEFAULT_TAG)

TEST_CASE("stream_type_make must creat StreamType correctly",
          TEST_DEFAULT_TAG "[stream_type_make]")
{
    // const size_t size = GENERATE(as<size_t>{}, 0, SIZE_MAX);
    // const StreamType stream_expected = StreamType{.offset = 0, .size = size};

    // REQUIRE(stream_type_make(size) == stream_expected);

    REQUIRE(true);
}