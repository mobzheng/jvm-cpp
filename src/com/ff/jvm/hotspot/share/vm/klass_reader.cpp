//
// Created by zhengzhipeng on 2021/6/7.
//

#include "../../../../../../../include/klass_reader.h"


byte *klass_reader::readU1() {
    byte *temparr = (byte *) malloc(sizeof(byte) * 1);
//    printf("read  %s %d  = %d\n",__FUNCTION__ ,index, bytes[index]);
    temparr[0] = bytes[index++];
    return temparr;
}

byte *klass_reader::readU2() {
    byte *temparr = (byte *) malloc(sizeof(byte) * 2);
    for (int i = 0; i < 2; ++i) {
//        printf("read  %s %d  = %d\n",__FUNCTION__ ,index, bytes[index]);
        temparr[i] = bytes[index++];
    }
    return temparr;
}

byte *klass_reader::readU4() {
    byte *temparr = (byte *) malloc(sizeof(byte) * 4);
    for (int i = 0; i < 4; ++i) {
//        printf("read  %s %d  = %d\n",__FUNCTION__ ,index, bytes[index]);
        temparr[i] = bytes[index++];
    }
    return temparr;

}

byte *klass_reader::readU8() {
    byte *temparr = (byte *) malloc(sizeof(byte) * 4);
    for (int i = 0; i < 8; ++i) {
        temparr[i] = bytes[index++];
    }
    return temparr;
}

byte *klass_reader::getBytes() const {
    return bytes;
}

void klass_reader::setBytes(byte *bytes) {
    klass_reader::bytes = bytes;
}

int klass_reader::getIndex() const {
    return index;
}

void klass_reader::setIndex(int index) {
    klass_reader::index = index;
}

int klass_reader::readU1Simple() {

    byte *buf = readU1();
    return buf[0];
}

int klass_reader::readU2Simple() {
    byte *buf = readU2();
    int low = (buf[1] & 0xff);
    int high = (buf[0] & 0xff);
    return high << 8 | low;
}

byte *klass_reader::read(int len) {
    byte *buf = (byte *) malloc(len * sizeof(byte));
    for (int i = 0; i < len; ++i) {
        buf[i] = bytes[index++];
    }
    return buf;
}

int klass_reader::readU4Simple() {
    int high = readU2Simple();
    int low = readU2Simple();
    return high << 16 | low;
}

long klass_reader::readU8Simple() {
    int high = readU4Simple();
    int low = readU4Simple();
    return high << 16 | low;
}

klass_reader::klass_reader(byte *buf, int len):len(len),bytes(buf),index(0) {

}
