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

#define is_memory_make(MEMORY_READ_CALLBACK, MEMORY_INITIAL_OFFSET, SIZE) \
    {.stream         = stream_type_make(SIZE), \
     .initial_offset = MEMORY_INITIAL_OFFSET, \
     .read_callback  = MEMORY_READ_CALLBACK}
// clang-format off

typedef bool (*MemoryReadCallback)(uint8_t *dest_ptr, size_t size, size_t offset);

typedef struct InputStreamMemory
{
    StreamType stream;
    const size_t initial_offset;
    const MemoryReadCallback read_callback;
} InputStreamMemory;

uint8_t is_memory_read_u8(StreamType *is);

#ifdef __cplusplus
}
#endif

#endif // INPUT_STREAM_MEMORY