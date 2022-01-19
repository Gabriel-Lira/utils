#ifndef INPUT_STREAM
#define INPUT_STREAM

#include "stream/input/input_stream_buffer.h"
#include "stream/input/input_stream_memory.h"
#include "stream/stream_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

// clang-format off
#define is_read(IS, VAR) _Generic((IS), \
    InputStreamBuffer: is_buffer_read(IS, VAR), \
    InputStreamMemory: is_memory_read(IS, VAR))

#define is_available(IS) stream_type_available(&IS.stream)

#define is_shift_ledt(IS, SHIFT_SIZE) stream_type_shift_left(&IS.stream, SHIFT_SIZE)
#define is_shift_right(IS, SHIFT_SIZE) stream_type_shift_right(&IS.stream, SHIFT_SIZE)
// clang-format off

#ifdef __cplusplus
}
#endif

#endif // INPUT_STREAM