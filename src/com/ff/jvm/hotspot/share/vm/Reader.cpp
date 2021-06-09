//
// Created by zhengzhipeng on 2021/6/7.
//

#include "../../../../../../../include/Reader.h"


byte *Reader::readU1() {
    byte *temparr = (byte *) malloc(sizeof(byte) * 1);
//    printf("read  %s %d  = %d\n",__FUNCTION__ ,index, bytes[index]);
    temparr[0] = bytes[index++];
    return temparr;
}

byte *Reader::readU2() {
    byte *temparr = (byte *) malloc(sizeof(byte) * 2);
    for (int i = 0; i < 2; ++i) {
//        printf("read  %s %d  = %d\n",__FUNCTION__ ,index, bytes[index]);
        temparr[i] = bytes[index++];
    }
    return temparr;
}

byte *Reader::readU4() {
    byte *temparr = (byte *) malloc(sizeof(byte) * 4);
    for (int i = 0; i < 4; ++i) {
//        printf("read  %s %d  = %d\n",__FUNCTION__ ,index, bytes[index]);
        temparr[i] = bytes[index++];
    }
    return temparr;

}

byte *Reader::readU8() {
    byte *temparr = (byte *) malloc(sizeof(byte) * 4);
    for (int i = 0; i < 8; ++i) {
//        printf("read  %s %d  = %d\n",__FUNCTION__ ,index, bytes[index]);
        temparr[i] = bytes[index++];
    }
    return temparr;
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

int Reader::readU1Simple() {

    byte *buf = readU1();
    return buf[0];
}

int Reader::readU2Simple() {
    byte *buf = readU2();
    int low = (buf[1] & 0xff);
    int high = (buf[0] & 0xff);
    return high << 8 | low;
}

byte *Reader::read(int len) {
    byte *buf = (byte *) malloc(len * sizeof(byte));
    for (int i = 0; i < len; ++i) {
        buf[i] = bytes[index++];
    }
    return buf;
}

int Reader::readU4Simple() {
    int high = readU2Simple();
    int low = readU2Simple();
    return high << 16 | low;
}

long Reader::readU8Simple() {
    int high = readU4Simple();
    int low = readU4Simple();
    return high << 16 | low;
}

Reader::Reader(byte *buf, int len) {
    Reader::bytes=buf;
    Reader::index = 0;
    Reader::len = len;

}
