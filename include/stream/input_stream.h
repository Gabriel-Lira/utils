#ifndef INPUT_STREAM
#define INPUT_STREAM

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

// clang-format off
#define is_read(IS, VAR) VAR = _Generic((VAR), \
    uint8_t: is_read_u8, \
    uint16_t: is_read_u16, \
    uint32_t: is_read_u32, \
    uint64_t: is_read_u64) \
    (&IS)
// clang-format off

typedef struct InputStream
{
    uint16_t offset;
    const uint16_t size;
    const uint8_t *const buffer_ptr;
} InputStream;

InputStream is_make(const uint8_t*buffer_ptr, uint16_t size);

uint16_t is_available(InputStream *is);

uint8_t is_read_u8(InputStream *is);
uint16_t is_read_u16(InputStream *is);
uint32_t is_read_u32(InputStream *is);
uint64_t is_read_u64(InputStream *is);

#ifdef __cplusplus
}
#endif

#endif // INPUT_STREAM