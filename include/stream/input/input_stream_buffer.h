#ifndef INPUT_STREAM_BUFFER
#define INPUT_STREAM_BUFFER

#include "stream/input/input_stream_type.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

// clang-format off
#define is_buffer_read(IS, VAR) is_type_read(IS, VAR, is_buffer_read_u8)
// clang-format off

typedef struct InputStreamBuffer
{
    InputStreamType stream;
    const uint8_t *const buffer_ptr;
} InputStreamBuffer;

InputStreamBuffer is_buffer_make(const uint8_t*buffer_ptr, size_t size);

uint8_t is_buffer_read_u8(InputStreamType *is);

#ifdef __cplusplus
}
#endif

#endif // INPUT_STREAM_BUFFER