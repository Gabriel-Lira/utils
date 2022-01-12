#include "stream/output/output_stream_type.h"

size_t os_type_available(OutputStreamType *os)
{
    return (os->size - os->offset);
}

void os_type_advance(OutputStreamType *os, size_t advance_size)
{
    if ((os->offset + advance_size) <= os->size)
    {
        os->offset += advance_size;
    }
    else
    {
        os->offset = os->size;
    }
}

void os_type_write_u8(OutputStreamType *os, uint8_t src_var,
                      OsTypeWriteU8Callback write_u8_callback)
{
    if (os_type_available(os) < sizeof(uint8_t))
    {
        return;
    }

    write_u8_callback(os, src_var);
}

void os_type_write_u16(OutputStreamType *os, uint16_t src_var,
                       OsTypeWriteU8Callback write_u8_callback)
{
    os_type_write_u8(os, (uint8_t)(src_var >> 8), write_u8_callback);
    os_type_write_u8(os, (uint8_t)(src_var), write_u8_callback);
}

void os_type_write_u32(OutputStreamType *os, uint32_t src_var,
                       OsTypeWriteU8Callback write_u8_callback)
{
    os_type_write_u16(os, (uint16_t)(src_var >> 16), write_u8_callback);
    os_type_write_u16(os, (uint16_t)(src_var), write_u8_callback);
}

void os_type_write_u64(OutputStreamType *os, uint64_t src_var,
                       OsTypeWriteU8Callback write_u8_callback)
{
    os_type_write_u32(os, (uint32_t)(src_var >> 32), write_u8_callback);
    os_type_write_u32(os, (uint32_t)(src_var), write_u8_callback);
}
