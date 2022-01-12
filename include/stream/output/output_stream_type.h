#ifndef OUTPUT_STREAM_TYPE
#define OUTPUT_STREAM_TYPE

#include "stream/stream_type.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

// clang-format off
#define os_type_write(OS, VAR, CALLBACK) _Generic((VAR), \
    uint8_t: os_type_write_u8, \
    uint16_t: os_type_write_u16, \
    uint32_t: os_type_write_u32, \
    uint64_t: os_type_write_u64) \
    (&OS, VAR, CALLBACK)
// clang-format off

typedef void (*OsTypeWriteU8Callback)(StreamType *os, uint8_t src_var);

void os_type_write_u8(StreamType *os, uint8_t src_var, OsTypeWriteU8Callback write_u8_callback);
void os_type_write_u16(StreamType *os, uint16_t src_var, OsTypeWriteU8Callback write_u8_callback);
void os_type_write_u32(StreamType *os, uint32_t src_var, OsTypeWriteU8Callback write_u8_callback);
void os_type_write_u64(StreamType *os, uint64_t src_var, OsTypeWriteU8Callback write_u8_callback);

#ifdef __cplusplus
}
#endif

#endif // OUTPUT_STREAM_TYPE