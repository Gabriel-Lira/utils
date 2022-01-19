#ifndef OUTPUT_STREAM
#define OUTPUT_STREAM

#include "stream/output/output_stream_buffer.h"
#include "stream/output/output_stream_memory.h"
#include "stream/stream_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

// clang-format off
#define os_write(OS, VAR) _Generic((OS), \
    OutputStreamBuffer: os_buffer_write(OS, VAR), \
    OutputStreamMemory: os_memory_write(OS, VAR))

#define os_available(OS) stream_type_available(&OS.stream)

#define os_shift_ledt(OS, SHIFT_SIZE) stream_type_shift_left(&OS.stream, SHIFT_SIZE)
#define os_shift_right(OS, SHIFT_SIZE) stream_type_shift_right(&OS.stream, SHIFT_SIZE)
// clang-format off

#ifdef __cplusplus
}
#endif

#endif // OUTPUT_STREAM