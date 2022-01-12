#ifndef OUTPUT_STREAM
#define OUTPUT_STREAM

#include "stream/output/output_stream_buffer.h"
#include "stream/output/output_stream_memory.h"

#ifdef __cplusplus
extern "C"
{
#endif

// clang-format off
#define os_write(OS, VAR) _Generic((OS), \
    OutputStreamBuffer: os_buffer_write(OS, VAR), \
    OutputStreamMemory: os_memory_write(OS, VAR))

#define os_available(OS) os_type_available(&OS.stream)

#define os_advance(OS, ADVANCE_SIZE) os_type_advance(&OS.stream, ADVANCE_SIZE)
// clang-format off

#ifdef __cplusplus
}
#endif

#endif // OUTPUT_STREAM