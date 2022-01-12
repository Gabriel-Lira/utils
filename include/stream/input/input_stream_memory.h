#ifndef INPUT_STREAM_MEMORY
#define INPUT_STREAM_MEMORY

#include "stream/input/input_stream_type.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

// clang-format off
#define is_memory_read(IS, VAR) is_type_read(IS.stream, VAR, is_memory_read_u8)
// clang-format off

typedef bool (*MemoryReadCallback)(uint8_t *dest_ptr, size_t size, size_t offset);

typedef struct InputStreamMemory
{
    InputStreamType stream;
    const size_t initial_offset;
    const MemoryReadCallback read_callback;
} InputStreamMemory;

InputStreamMemory is_memory_make(MemoryReadCallback memory_read_callback, size_t memory_initial_offset, size_t size);

uint8_t is_memory_read_u8(InputStreamType *is);

#ifdef __cplusplus
}
#endif

#endif // INPUT_STREAM_MEMORY