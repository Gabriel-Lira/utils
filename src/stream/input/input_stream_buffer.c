#include "stream/input/input_stream_buffer.h"

InputStreamBuffer is_buffer_make(const uint8_t *buffer_ptr, size_t size)
{
    return (InputStreamBuffer){.buffer_ptr = buffer_ptr,
                               .stream = stream_type_make(size)};
}

uint8_t is_buffer_read_u8(StreamType *is)
{
    InputStreamBuffer *is_buffer = (InputStreamBuffer *)is;

    return is_buffer->buffer_ptr[is_buffer->stream.offset++];
}
