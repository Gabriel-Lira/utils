#include "stream/input/input_stream_type.h"

size_t is_type_available(InputStreamType *is)
{
    return (is->size - is->offset);
}

void is_type_advance(InputStreamType *is, size_t advance_size)
{
    if ((is->offset + advance_size) <= is->size)
    {
        is->offset += advance_size;
    }
    else
    {
        is->offset = is->size;
    }
}
