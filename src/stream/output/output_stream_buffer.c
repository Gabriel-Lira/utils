#include "stream/output/output_stream_buffer.h"

void os_buffer_write_u8(StreamType *os, uint8_t src_var)
{
    OutputStreamBuffer *os_buffer = (OutputStreamBuffer *)os;

    os_buffer->buffer_ptr[os_buffer->stream.offset++] = src_var;
}
