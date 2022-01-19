#include "stream/stream_type.h"

size_t stream_type_available(StreamType *stream)
{
    return (stream->size - stream->offset);
}

void stream_type_advance(StreamType *stream, size_t advance_size)
{
    if ((stream->offset + advance_size) <= stream->size)
    {
        stream->offset += advance_size;
    }
    else
    {
        stream->offset = stream->size;
    }
}
