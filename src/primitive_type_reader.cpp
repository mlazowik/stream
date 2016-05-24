#include "primitive_type_reader.h"

template <typename T>
PrimitiveTypeReader::PrimitiveTypeReader(Stream &stream) : stream(stream) {
    this->value = new T;
    this->streamReader = new StreamReader(stream, (char*)this->value,
                                          sizeof(*this->value));
}

PrimitiveTypeReader::~PrimitiveTypeReader() {
    delete this->value;
    delete this->streamReader;
}

void PrimitiveTypeReader::readNextChunk() {
    this->streamReader->readNextChunk();
}

bool PrimitiveTypeReader::finished() const {
    return this->streamReader->finished();
}

template <typename T>
T PrimitiveTypeReader::getValue() const {
    if (!this->finished()) {
        throw std::logic_error("cannot return value, still reading");
    }

    T value = *this->value;
    return value;
}