#ifndef INPUT_STREAM_TYPE
#define INPUT_STREAM_TYPE

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

    // clang-format off

typedef struct InputStreamType
{
    size_t offset;
    const size_t size;
} InputStreamType;

size_t is_type_available(InputStreamType *is);
size_t is_type_advance(InputStreamType *is, size_t advance_size);

#ifdef __cplusplus
}
#endif

#endif // INPUT_STREAM_TYPE