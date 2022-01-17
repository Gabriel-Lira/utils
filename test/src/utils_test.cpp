#include "utils_test.hpp"

bool operator==(StreamType s1, StreamType s2)
{
    return (s1.offset == s2.offset) && (s1.size == s2.size);
}