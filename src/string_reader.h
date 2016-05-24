#ifndef CHAT_STRING_READER_H
#define CHAT_STRING_READER_H

#include <string>
#include <functional>
#include "reader.h"
#include "stream.h"
#include "stream_reader.h"
#include "primitive_type_reader.h"

class StringReader : public Reader {
public:
    StringReader(Stream &stream, std::function<bool(std::string)> finished);
    ~StringReader();

    void readNextChunk();
    bool finished() const;

    std::string getValue() const;

private:
    Stream &stream;

    std::function<bool(std::string)> finishedCallback;

    std::string value;
    PrimitiveTypeReader<char> *charReader;

    PrimitiveTypeReader<char> *getCharReader();
};

#endif //CHAT_STRING_READER_H
