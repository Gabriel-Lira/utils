#include "stream/output/output_stream_memory.h"

void os_memory_write_u8(StreamType *os, uint8_t src_var)
{
    OutputStreamMemory *os_buffer = (OutputStreamMemory *)os;
    const size_t write_offset =
        (os_buffer->initial_offset + os_buffer->stream.offset++);

    os_buffer->write_callback(&src_var, sizeof(uint8_t), write_offset);
}
