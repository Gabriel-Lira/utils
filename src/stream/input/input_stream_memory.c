#include "stream/input/input_stream_memory.h"

InputStreamMemory is_memory_make(MemoryReadCallback memory_read_callback,
                                 size_t memory_initial_offset, size_t size)
{
    return (InputStreamMemory){
        .read_callback = memory_read_callback,
        .initial_offset = memory_initial_offset,
        .stream = (InputStreamType){.size = size, .offset = 0}};
}

uint8_t is_memory_read_u8(InputStreamMemory *is)
{
    if (is_type_available(&is->stream) < sizeof(uint8_t))
    {
        return 0;
    }

    uint8_t value = 0;
    is->read_callback(&value, sizeof(uint8_t),
                      (is->initial_offset + is->stream.offset++));

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
