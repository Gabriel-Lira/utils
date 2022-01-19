#include "stream/stream_type.h"

size_t stream_type_available(StreamType *stream)
{
    return (stream->size - stream->offset);
}

void stream_type_shift_left(StreamType *stream, size_t shift_size)
{
    if (stream->offset >= shift_size)
    {
        stream->offset -= shift_size;
    }
    else
    {
        stream->offset = 0;
    }
}

void stream_type_shift_right(StreamType *stream, size_t shift_size)
{
    if ((stream->offset + shift_size) <= stream->size)
    {
        stream->offset += shift_size;
    }
    else
    {
        stream->offset = stream->size;
    }
}
