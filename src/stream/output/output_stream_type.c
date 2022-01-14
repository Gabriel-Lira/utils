#include "stream/output/output_stream_type.h"

void os_type_write_u8(StreamType *os, uint8_t src_var,
                      OsTypeWriteU8Callback write_u8_callback)
{
    if (stream_type_available(os) < sizeof(uint8_t))
    {
        return;
    }

    write_u8_callback(os, src_var);
}

void os_type_write_u16(StreamType *os, uint16_t src_var,
                       OsTypeWriteU8Callback write_u8_callback)
{
    os_type_write_u8(os, (uint8_t)(src_var >> 8), write_u8_callback);
    os_type_write_u8(os, (uint8_t)(src_var), write_u8_callback);
}

void os_type_write_u32(StreamType *os, uint32_t src_var,
                       OsTypeWriteU8Callback write_u8_callback)
{
    os_type_write_u16(os, (uint16_t)(src_var >> 16), write_u8_callback);
    os_type_write_u16(os, (uint16_t)(src_var), write_u8_callback);
}

void os_type_write_u64(StreamType *os, uint64_t src_var,
                       OsTypeWriteU8Callback write_u8_callback)
{
    os_type_write_u32(os, (uint32_t)(src_var >> 32), write_u8_callback);
    os_type_write_u32(os, (uint32_t)(src_var), write_u8_callback);
}
