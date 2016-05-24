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

template <typename T>
PrimitiveTypeReader<T>::PrimitiveTypeReader(Stream &stream) : stream(stream) {
    this->value = new T;
    this->streamReader = new StreamReader(stream, (char*)this->value,
                                          sizeof(*this->value));
}

template <typename T>
PrimitiveTypeReader<T>::~PrimitiveTypeReader() {
    delete this->value;
    delete this->streamReader;
}

template <typename T>
void PrimitiveTypeReader<T>::readNextChunk() {
    this->streamReader->readNextChunk();
}

template <typename T>
bool PrimitiveTypeReader<T>::finished() const {
    return this->streamReader->finished();
}

template <typename T>
T PrimitiveTypeReader<T>::getValue() const {
    if (!this->finished()) {
        throw std::logic_error("cannot return value, still reading");
    }

    T value = *this->value;
    return value;
}

#endif //CHAT_PRIMITIVE_TYPE_READER_H
