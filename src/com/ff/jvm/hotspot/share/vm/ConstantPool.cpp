//
// Created by zhengzhipeng on 2021/6/8.
//

#include "../../../../../../../include/ConstantPool.h"

int *ConstantPool::getTag()  {
    return tag;
}

void ConstantPool::setTag(int *tag) {
    ConstantPool::tag = tag;
}

const map<int, byte *> &ConstantPool::getDatamap() const {
    return datamap;
}

void ConstantPool::setDatamap(const map<int, byte *> &datamap) {
    ConstantPool::datamap = datamap;
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

ConstantPool::ConstantPool(Klass *_klass) {

    ConstantPool::klass = _klass;

}
