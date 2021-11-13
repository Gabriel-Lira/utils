#ifndef INPUT_STREAM_MEMORY
#define INPUT_STREAM_MEMORY

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

// clang-format off
#define is_memory_read(IS, VAR) VAR = _Generic((VAR), \
    uint8_t: is_memory_read_u8, \
    uint16_t: is_memory_read_u16, \
    uint32_t: is_memory_read_u32, \
    uint64_t: is_memory_read_u64) \
    (&IS)
// clang-format off

typedef bool (*MemoryReadCallback)(uint8_t *dest_ptr, size_t size, size_t offset);

typedef struct InputStreamMemory
{
    size_t offset;
    const size_t initial_offset;
    const size_t size;
    const MemoryReadCallback read_callback;
} InputStreamMemory;

InputStreamMemory is_memory_make(MemoryReadCallback memory_read_callback, size_t memory_initial_offset, size_t size);

size_t is_memory_available(InputStreamMemory *is);

uint8_t is_memory_read_u8(InputStreamMemory *is);
uint16_t is_memory_read_u16(InputStreamMemory *is);
uint32_t is_memory_read_u32(InputStreamMemory *is);
uint64_t is_memory_read_u64(InputStreamMemory *is);

#ifdef __cplusplus
}
#endif

#endif // INPUT_STREAM_MEMORY