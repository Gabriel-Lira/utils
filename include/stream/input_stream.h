#ifndef INPUT_STREAM
#define INPUT_STREAM

#include "stream/input_stream_buffer.h"
#include "stream/input_stream_memory.h"

#ifdef __cplusplus
extern "C"
{
#endif

// clang-format off
#define is_read(IS, VAR) _Generic((IS), \
    InputStreamBuffer: is_buffer_read(IS, VAR), \
    InputStreamMemory: is_memory_read(IS, VAR))
// clang-format off

// clang-format off
#define is_available(IS) is_type_available(IS.stream)
// clang-format off

// clang-format off
#define is_advance(IS, ADVANCE_SIZE) is_type_advance(IS.stream, ADVANCE_SIZE)
// clang-format off

#ifdef __cplusplus
}
#endif

#endif // INPUT_STREAM