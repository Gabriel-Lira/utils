#ifndef INPUT_STREAM_BUFFER
#define INPUT_STREAM_BUFFER

#include "stream/input_stream_type.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

// clang-format off
#define is_buffer_read(IS, VAR) VAR = _Generic((VAR), \
    uint8_t: is_buffer_read_u8, \
    uint16_t: is_buffer_read_u16, \
    uint32_t: is_buffer_read_u32, \
    uint64_t: is_buffer_read_u64) \
    (&IS)
// clang-format off

typedef struct InputStreamBuffer
{
    InputStreamType stream;
    const uint8_t *const buffer_ptr;
} InputStreamBuffer;

InputStreamBuffer is_buffer_make(const uint8_t*buffer_ptr, size_t size);

uint8_t is_buffer_read_u8(InputStreamBuffer *is);
uint16_t is_buffer_read_u16(InputStreamBuffer *is);
uint32_t is_buffer_read_u32(InputStreamBuffer *is);
uint64_t is_buffer_read_u64(InputStreamBuffer *is);

#ifdef __cplusplus
}
#endif

#endif // INPUT_STREAM_BUFFER