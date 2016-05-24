#include "string_reader.h"

StringReader::StringReader(Stream &stream,
                           std::function<bool(std::string)> finished)
        : stream(stream), finishedCallback(finished) {
    this->charReader = this->getCharReader();
}

StringReader::~StringReader() {
    delete this->charReader;
}

void StringReader::readNextChunk() {
    if (this->finished()) {
        throw std::logic_error("cannot read: already finished");
    }

    this->charReader->readNextChunk();

    if (this->charReader->finished()) {
        this->value += this->charReader->getValue();
        delete this->charReader;
        this->charReader = getCharReader();
    }
}

bool StringReader::finished() const {
    return this->finishedCallback(this->value);
}

std::string StringReader::getValue() const {
    return this->value;
}

PrimitiveTypeReader<char> *StringReader::getCharReader() {
    return new PrimitiveTypeReader<char>(this->stream);
}