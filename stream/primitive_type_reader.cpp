#include "primitive_type_reader.h"

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