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
// clang-format off

typedef bool (*MemoryWriteCallback)(uint8_t *src_ptr, size_t size, size_t offset);

typedef struct OutputStreamMemory
{
    StreamType stream;
    const size_t initial_offset;
    const MemoryWriteCallback write_callback;
} OutputStreamMemory;

OutputStreamMemory os_memory_make(MemoryWriteCallback memory_write_callback, size_t memory_initial_offset, size_t size);

void os_memory_write_u8(StreamType *os, uint8_t src_var);

#ifdef __cplusplus
}
#endif

#endif // OUTPUT_STREAM_MEMORY