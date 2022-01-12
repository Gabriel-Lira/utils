#ifndef OUTPUT_STREAM_TYPE
#define OUTPUT_STREAM_TYPE

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

typedef struct OutputStreamType
{
    size_t offset;
    const size_t size;
} OutputStreamType;

typedef void (*OsTypeWriteU8Callback)(OutputStreamType *os, uint8_t src_var);

size_t os_type_available(OutputStreamType *os);
void os_type_advance(OutputStreamType *os, size_t advance_size);

void os_type_write_u8(OutputStreamType *os, uint8_t src_var, OsTypeWriteU8Callback write_u8_callback);
void os_type_write_u16(OutputStreamType *os, uint16_t src_var, OsTypeWriteU8Callback write_u8_callback);
void os_type_write_u32(OutputStreamType *os, uint32_t src_var, OsTypeWriteU8Callback write_u8_callback);
void os_type_write_u64(OutputStreamType *os, uint64_t src_var, OsTypeWriteU8Callback write_u8_callback);

#ifdef __cplusplus
}
#endif

#endif // OUTPUT_STREAM_TYPE