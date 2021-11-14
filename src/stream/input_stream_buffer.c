#include "stream/input_stream_buffer.h"

InputStreamBuffer is_buffer_make(const uint8_t *buffer_ptr, size_t size)
{
    return (InputStreamBuffer){
        .buffer_ptr = buffer_ptr,
        .stream = (InputStreamType){.size = size, .offset = 0}};
}

uint8_t is_buffer_read_u8(InputStreamBuffer *is)
{
    if (is_type_available(&is->stream) < sizeof(uint8_t))
    {
        return 0;
    }

    return is->buffer_ptr[is->stream.offset++];
}

uint16_t is_buffer_read_u16(InputStreamBuffer *is)
{
    return (((uint16_t)is_buffer_read_u8(is) << 8) | is_buffer_read_u8(is));
}

uint32_t is_buffer_read_u32(InputStreamBuffer *is)
{
    return (((uint32_t)is_buffer_read_u16(is) << 16) | is_buffer_read_u16(is));
}

uint64_t is_buffer_read_u64(InputStreamBuffer *is)
{
    return (((uint64_t)is_buffer_read_u32(is) << 32) | is_buffer_read_u32(is));
}
