#ifndef CHAT_PIRMITIVE_TYPE_READER_H
#define CHAT_PIRMITIVE_TYPE_READER_H

#include "reader.h"
#include "stream.h"
#include "stream_reader.h"

template <typename T>
class PrimitiveTypeReader : public Reader {
public:
    PrimitiveTypeReader(Stream &stream);
    ~PrimitiveTypeReader();

    void readNextChunk();
    bool finished() const;

    T getValue() const;

private:
    Stream &stream;

    T *value;
    StreamReader *streamReader;
};

#endif //CHAT_PRIMITIVE_TYPE_READER_H
