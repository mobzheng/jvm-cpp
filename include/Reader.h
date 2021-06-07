//
// Created by zhengzhipeng on 2021/6/7.
//

#ifndef JVM_CPP_READER_H
#define JVM_CPP_READER_H
#include"common.h"
class Reader {
private:
    byte * bytes;
    int index;


public:
    Reader(byte* buf){
        bytes=buf;
        index = 0;
    };

    void readU1(byte arr[]);

    void readU2(byte arr[]);

    void readU4(byte arr[]);

    void readU8(byte arr[]);

    byte *getBytes() const;

    void setBytes(byte *bytes);

    int getIndex() const;

    void setIndex(int index);
};



#endif //JVM_CPP_READER_H
