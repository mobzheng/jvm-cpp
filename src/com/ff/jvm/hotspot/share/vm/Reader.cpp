//
// Created by zhengzhipeng on 2021/6/7.
//

#include <cstdio>
#include "../../../../../../../include/Reader.h"


void Reader::readU1(byte *arr) {
    arr[0] = bytes[index++];
}

void Reader::readU2(byte arr[]) {
    for (int i = 0; i < 2; ++i) {
        printf("read %d  = %d\n", index, bytes[index]);
        arr[i] = bytes[index++];
    }
}

void Reader::readU4(byte arr[]) {
    for (int i = 0; i < 4; ++i) {
        printf("read %d  = %d\n", index, bytes[index]);
        arr[i] = bytes[index++];
    }

}

void Reader::readU8(byte arr[]) {
    for (int i = 0; i < 8; ++i) {
        arr[i] = bytes[index++];
    }
}

byte *Reader::getBytes() const {
    return bytes;
}

void Reader::setBytes(byte *bytes) {
    Reader::bytes = bytes;
}

int Reader::getIndex() const {
    return index;
}

void Reader::setIndex(int index) {
    Reader::index = index;
}
