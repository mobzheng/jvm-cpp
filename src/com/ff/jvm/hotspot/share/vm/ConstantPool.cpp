//
// Created by zhengzhipeng on 2021/6/8.
//

#include "../../../../../../../include/ConstantPool.h"

int *ConstantPool::getTag() {
    return tag;
}

void ConstantPool::setTag(int *tag) {
    ConstantPool::tag = tag;
}

int ConstantPool::getLen() const {
    return len;
}

void ConstantPool::setLen(int len) {
    ConstantPool::len = len;
}


void ConstantPool::addItem(int tag, int index, byte *val) {
    ConstantPool::tag[index] = tag;
    ConstantPool::datamap[index] = val;
}

ConstantPool::ConstantPool(Klass *_klass, int len) {
    ConstantPool::len = len;
    ConstantPool::klass = _klass;
}

Klass *ConstantPool::getKlass() const {
    return klass;
}

void ConstantPool::setKlass(Klass *klass) {
    ConstantPool::klass = klass;
}

 map<int, byte *> ConstantPool::getDatamap()  {
    return datamap;
}

void ConstantPool::setDatamap(const map<int, byte *> &datamap) {
    ConstantPool::datamap = datamap;
}


