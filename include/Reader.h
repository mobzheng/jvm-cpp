//
// Created by zhengzhipeng on 2021/6/7.
//

#ifndef JVM_CPP_READER_H
#define JVM_CPP_READER_H
#include"common.h"
#include <iostream>
class Reader {
private:
    byte * bytes;
    int index;


public:
    Reader(byte* buf){
        bytes=buf;
        index = 0;
    };

    byte* readU1();

    byte *readU2();

    byte *readU4();

    byte *readU8();

    int readU1Simple();

    byte *getBytes() const;

    void setBytes(byte *bytes);

    int getIndex() const;

    void setIndex(int index);

    int readU2Simple();

    byte * read(int len);

    int readU4Simple();

    long readU8Simple();
};



#endif //JVM_CPP_READER_H
