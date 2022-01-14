#include "stream/input/input_stream_type.h"

uint8_t is_type_read_u8(StreamType *is, IsTypeReadU8Callback read_u8_callback)
{
    if (stream_type_available(is) < sizeof(uint8_t))
    {
        return 0;
    }

    return read_u8_callback(is);
}

uint16_t is_type_read_u16(StreamType *is, IsTypeReadU8Callback read_u8_callback)
{
    return (((uint16_t)is_type_read_u8(is, read_u8_callback) << 8) |
            is_type_read_u8(is, read_u8_callback));
}

uint32_t is_type_read_u32(StreamType *is, IsTypeReadU8Callback read_u8_callback)
{
    return (((uint32_t)is_type_read_u16(is, read_u8_callback) << 16) |
            is_type_read_u16(is, read_u8_callback));
}

uint64_t is_type_read_u64(StreamType *is, IsTypeReadU8Callback read_u8_callback)
{
    return (((uint64_t)is_type_read_u32(is, read_u8_callback) << 32) |
            is_type_read_u32(is, read_u8_callback));
}
