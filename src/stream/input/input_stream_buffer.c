#include "stream/input/input_stream_buffer.h"

InputStreamBuffer is_buffer_make(const uint8_t *buffer_ptr, size_t size)
{
    return (InputStreamBuffer){
        .buffer_ptr = buffer_ptr,
        .stream = (InputStreamType){.size = size, .offset = 0}};
}

uint8_t is_buffer_read_u8(InputStreamType *is)
{
    InputStreamBuffer *is_buffer = (InputStreamBuffer *)is;

    return is_buffer->buffer_ptr[is_buffer->stream.offset++];
}
