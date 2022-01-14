#include "stream/input/input_stream_memory.h"

InputStreamMemory is_memory_make(MemoryReadCallback memory_read_callback,
                                 size_t memory_initial_offset, size_t size)
{
    return (InputStreamMemory){.read_callback = memory_read_callback,
                               .initial_offset = memory_initial_offset,
                               .stream = stream_type_make(size)};
}

uint8_t is_memory_read_u8(StreamType *is)
{
    InputStreamMemory *is_buffer = (InputStreamMemory *)is;
    const size_t read_offset =
        (is_buffer->initial_offset + is_buffer->stream.offset++);

    uint8_t value = 0;
    is_buffer->read_callback(&value, sizeof(uint8_t), read_offset);

    return value;
}
