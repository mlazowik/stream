#include "line_reader.h"


LineReader::LineReader(StreamReader &charReader) : charReader(charReader) { }

void LineReader::readNextChunk() {
    if (this->charReader.finished()) {
        this->line +=
    }

    if (this->finished()) {
        throw std::logic_error("cannot read: already finished");
    }

    char c;

    size_t len = this->stream.getChunk(
            (char*)*c + this->bufferPosition, remains);

    if (len == 0) {
        throw stream_closed_error("connection closed");
    }
}