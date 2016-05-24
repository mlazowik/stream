#ifndef CHAT_HEADER_READER_H
#define CHAT_HEADER_READER_H

#include "reader.h"
#include "stream.h"
#include "stream_reader.h"

class LineReader : public Reader {
public:
    LineReader(StreamReader &charReader);
    void readNextChunk();

private:
    StreamReader &charReader;
    std::string line;
};

#endif //CHAT_HEADER_READER_H
