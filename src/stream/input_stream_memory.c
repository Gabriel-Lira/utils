#include "stream/input_stream_memory.h"

InputStreamMemory is_memory_make(MemoryReadCallback memory_read_callback,
                                 uint32_t memory_initial_offset, uint16_t size)
{
    return (InputStreamMemory){.read_callback = memory_read_callback,
                               .size = size,
                               .initial_offset = memory_initial_offset,
                               .offset = 0};
}

uint16_t is_memory_available(InputStreamMemory *is)
{
    return (is->size - is->offset);
}

uint8_t is_memory_read_u8(InputStreamMemory *is)
{
    if (is_memory_available(is) < sizeof(uint8_t))
    {
        return 0;
    }

    uint8_t value = 0;
    is->read_callback(&value, sizeof(uint8_t),
                      (is->initial_offset + is->offset++));

    return value;
}

uint16_t is_memory_read_u16(InputStreamMemory *is)
{
    return (((uint16_t)is_memory_read_u8(is) << 8) | is_memory_read_u8(is));
}

uint32_t is_memory_read_u32(InputStreamMemory *is)
{
    return (((uint32_t)is_memory_read_u16(is) << 16) | is_memory_read_u16(is));
}

uint64_t is_memory_read_u64(InputStreamMemory *is)
{
    return (((uint64_t)is_memory_read_u32(is) << 32) | is_memory_read_u32(is));
}
