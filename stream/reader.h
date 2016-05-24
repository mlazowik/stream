#ifndef CHAT_READER_H
#define CHAT_READER_H

class Reader {
public:
    virtual ~Reader() {};
    virtual void readNextChunk() = 0;
    virtual bool finished() const = 0;
};

#endif //CHAT_READER_H
