#include "stream/output/output_stream_buffer.h"

OutputStreamBuffer os_buffer_make(uint8_t *const buffer_ptr, size_t size)
{
    return (OutputStreamBuffer){.buffer_ptr = buffer_ptr,
                                .stream = stream_type_make(size)};
}

void os_buffer_write_u8(StreamType *os, uint8_t src_var)
{
    OutputStreamBuffer *os_buffer = (OutputStreamBuffer *)os;

    os_buffer->buffer_ptr[os_buffer->stream.offset++] = src_var;
}
