#include "stream/input/input_stream_memory.h"

uint8_t is_memory_read_u8(StreamType *is)
{
    InputStreamMemory *is_buffer = (InputStreamMemory *)is;
    const size_t read_offset =
        (is_buffer->initial_offset + is_buffer->stream.offset++);

    uint8_t value = 0;
    is_buffer->read_callback(&value, sizeof(uint8_t), read_offset);

    return value;
}
