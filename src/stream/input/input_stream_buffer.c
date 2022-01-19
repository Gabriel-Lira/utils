#include "stream/input/input_stream_buffer.h"

uint8_t is_buffer_read_u8(StreamType *is)
{
    InputStreamBuffer *is_buffer = (InputStreamBuffer *)is;

    return is_buffer->buffer_ptr[is_buffer->stream.offset++];
}
