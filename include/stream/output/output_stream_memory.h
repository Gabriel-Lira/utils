#ifndef OUTPUT_STREAM_MEMORY
#define OUTPUT_STREAM_MEMORY

#include "stream/output/output_stream_type.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

// clang-format off
#define os_memory_write(OS, VAR) os_type_write(OS.stream, VAR, os_memory_write_u8)

#define os_memory_make(MEMORY_WRITE_CALLBACK, MEMORY_INITIAL_OFFSET, SIZE) \
    {.stream = stream_type_make(size), \
     .initial_offset = memory_initial_offset, \
     .write_callback = memory_write_callback}
// clang-format off

typedef bool (*MemoryWriteCallback)(const uint8_t *src_ptr, size_t size, size_t offset);

typedef struct OutputStreamMemory
{
    StreamType stream;
    const size_t initial_offset;
    const MemoryWriteCallback write_callback;
} OutputStreamMemory;

void os_memory_write_u8(StreamType *os, uint8_t src_var);

#ifdef __cplusplus
}
#endif

#endif // OUTPUT_STREAM_MEMORY