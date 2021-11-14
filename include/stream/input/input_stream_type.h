#ifndef INPUT_STREAM_TYPE
#define INPUT_STREAM_TYPE

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

typedef struct InputStreamType
{
    size_t offset;
    const size_t size;
} InputStreamType;

typedef uint8_t (*IsTypeReadU8Callback)(InputStreamType *is);

size_t is_type_available(InputStreamType *is);
void is_type_advance(InputStreamType *is, size_t advance_size);

uint8_t is_type_read_u8(InputStreamType *is, IsTypeReadU8Callback read_u8_callback);
uint16_t is_type_read_u16(InputStreamType *is, IsTypeReadU8Callback read_u8_callback);
uint32_t is_type_read_u32(InputStreamType *is, IsTypeReadU8Callback read_u8_callback);
uint64_t is_type_read_u64(InputStreamType *is, IsTypeReadU8Callback read_u8_callback);

#ifdef __cplusplus
}
#endif

#endif // INPUT_STREAM_TYPE