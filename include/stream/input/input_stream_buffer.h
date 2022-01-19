#ifndef INPUT_STREAM_BUFFER
#define INPUT_STREAM_BUFFER

#include "stream/input/input_stream_type.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

// clang-format off
#define is_buffer_read(IS, VAR) is_type_read(IS.stream, VAR, is_buffer_read_u8)

#define is_buffer_make(BUFFER_PTR, SIZE) {.stream = stream_type_make(SIZE), .buffer_ptr = BUFFER_PTR}
// clang-format off

typedef struct InputStreamBuffer
{
    StreamType stream;
    const uint8_t *const buffer_ptr;
} InputStreamBuffer;

uint8_t is_buffer_read_u8(StreamType *is);

#ifdef __cplusplus
}
#endif

#endif // INPUT_STREAM_BUFFER