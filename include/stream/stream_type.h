#ifndef STREAM_TYPE
#define STREAM_TYPE

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

    // clang-format off
#define stream_type_make(SIZE) {.offset = 0, .size = SIZE}

typedef struct StreamType
{
    size_t offset;
    const size_t size;
} StreamType;

size_t stream_type_available(StreamType *stream);

void stream_type_shift_left(StreamType *stream, size_t shift_size);
void stream_type_shift_right(StreamType *stream, size_t shift_size);

#ifdef __cplusplus
}
#endif

#endif // STREAM_TYPE