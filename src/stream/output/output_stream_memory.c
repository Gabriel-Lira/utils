#include "stream/output/output_stream_memory.h"

OutputStreamMemory os_memory_make(MemoryWriteCallback memory_write_callback,
                                  size_t memory_initial_offset, size_t size)
{
    return (OutputStreamMemory){.write_callback = memory_write_callback,
                                .initial_offset = memory_initial_offset,
                                .stream =
                                    (StreamType){.size = size, .offset = 0}};
}

void os_memory_write_u8(StreamType *os, uint8_t src_var)
{
    OutputStreamMemory *os_buffer = (OutputStreamMemory *)os;
    const size_t write_offset =
        (os_buffer->initial_offset + os_buffer->stream.offset++);

    os_buffer->write_callback(&src_var, sizeof(uint8_t), write_offset);
}
