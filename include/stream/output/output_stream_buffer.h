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
// clang-format off

typedef struct OutputStreamBuffer
{
    OutputStreamType stream;
    uint8_t *const buffer_ptr;
} OutputStreamBuffer;

OutputStreamBuffer os_buffer_make(uint8_t*const buffer_ptr, size_t size);

void os_buffer_write_u8(OutputStreamType *os, uint8_t src_var);

#ifdef __cplusplus
}
#endif

#endif // OUTPUT_STREAM_BUFFER