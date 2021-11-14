#include "stream/input/input_stream_type.h"

size_t is_type_available(InputStreamType *is)
{
    return (is->size - is->offset);
}

void is_type_advance(InputStreamType *is, size_t advance_size)
{
    if ((is->offset + advance_size) <= is->size)
    {
        is->offset += advance_size;
    }
    else
    {
        is->offset = is->size;
    }
}

uint8_t is_type_read_u8(InputStreamType *is,
                        IsTypeReadU8Callback read_u8_callback)
{
    if (is_type_available(is) < sizeof(uint8_t))
    {
        return 0;
    }

    return read_u8_callback(is);
}

uint16_t is_type_read_u16(InputStreamType *is,
                          IsTypeReadU8Callback read_u8_callback)
{
    return (((uint16_t)is_type_read_u8(is, read_u8_callback) << 8) |
            is_type_read_u8(is, read_u8_callback));
}

uint32_t is_type_read_u32(InputStreamType *is,
                          IsTypeReadU8Callback read_u8_callback)
{
    return (((uint32_t)is_type_read_u16(is, read_u8_callback) << 16) |
            is_type_read_u16(is, read_u8_callback));
}

uint64_t is_type_read_u64(InputStreamType *is,
                          IsTypeReadU8Callback read_u8_callback)
{
    return (((uint64_t)is_type_read_u32(is, read_u8_callback) << 32) |
            is_type_read_u32(is, read_u8_callback));
}
