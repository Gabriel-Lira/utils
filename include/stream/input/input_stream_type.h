#ifndef INPUT_STREAM_TYPE
#define INPUT_STREAM_TYPE

#include "stream/stream_type.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

// clang-format off
#define is_type_read(IS, VAR, CALLBACK) VAR = _Generic((VAR), \
    uint8_t: is_type_read_u8, \
    uint16_t: is_type_read_u16, \
    uint32_t: is_type_read_u32, \
    uint64_t: is_type_read_u64) \
    (&IS, CALLBACK)
// clang-format off

typedef uint8_t (*IsTypeReadU8Callback)(StreamType *is);

uint8_t is_type_read_u8(StreamType *is, IsTypeReadU8Callback read_u8_callback);
uint16_t is_type_read_u16(StreamType *is, IsTypeReadU8Callback read_u8_callback);
uint32_t is_type_read_u32(StreamType *is, IsTypeReadU8Callback read_u8_callback);
uint64_t is_type_read_u64(StreamType *is, IsTypeReadU8Callback read_u8_callback);

#ifdef __cplusplus
}
#endif

#endif // INPUT_STREAM_TYPE