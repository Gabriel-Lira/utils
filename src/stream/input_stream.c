#include "stream/input_stream.h"

InputStream is_make(const uint8_t *buffer_ptr, uint16_t size)
{
    return (InputStream){.buffer_ptr = buffer_ptr, .size = size, .offset = 0};
}

uint16_t is_available(InputStream *is)
{
    return (is->size - is->offset);
}

uint8_t is_read_u8(InputStream *is)
{
    if (is_available(is) < sizeof(uint8_t))
    {
        return 0;
    }

    return is->buffer_ptr[is->offset++];
}

uint16_t is_read_u16(InputStream *is)
{
    return (((uint16_t)is_read_u8(is) << 8) | is_read_u8(is));
}

uint32_t is_read_u32(InputStream *is)
{
    return (((uint32_t)is_read_u16(is) << 16) | is_read_u16(is));
}

uint64_t is_read_u64(InputStream *is)
{
    return (((uint64_t)is_read_u32(is) << 32) | is_read_u32(is));
}
