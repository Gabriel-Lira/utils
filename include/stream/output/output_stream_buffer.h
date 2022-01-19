#ifndef OUTPUT_STREAM_BUFFER
#define OUTPUT_STREAM_BUFFER

#include "stream/output/output_stream_type.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

// clang-format off
#define os_buffer_write(OS, VAR) os_type_write(OS.stream, VAR, os_buffer_write_u8)

#define os_buffer_make(BUFFER_PTR, SIZE) {.stream = stream_type_make(SIZE), .buffer_ptr = BUFFER_PTR}
// clang-format off

typedef struct OutputStreamBuffer
{
    StreamType stream;
    uint8_t *const buffer_ptr;
} OutputStreamBuffer;

void os_buffer_write_u8(StreamType *os, uint8_t src_var);

#ifdef __cplusplus
}
#endif

#endif // OUTPUT_STREAM_BUFFER