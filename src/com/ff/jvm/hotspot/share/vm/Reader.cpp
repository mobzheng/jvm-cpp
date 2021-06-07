//
// Created by zhengzhipeng on 2021/6/7.
//

#include "../../../../../../../include/Reader.h"


void Reader::readU1(byte **arr) {
    *arr[0] = bytes[index++];
}

void Reader::readU2(byte **arr) {
    for (int i = 0; i < sizeof(*arr) / sizeof(byte); ++i) {
        *arr[i] = bytes[index++];
    }
}

void Reader::readU4(byte **arr) {
    for (int i = 0; i < sizeof(*arr) / sizeof(byte); ++i) {
        *arr[i] = bytes[index++];
    }

}

void Reader::readU8(byte **arr) {
    for (int i = 0; i < sizeof(*arr) / sizeof(byte); ++i) {
        *arr[i] = bytes[index++];
    }
}
