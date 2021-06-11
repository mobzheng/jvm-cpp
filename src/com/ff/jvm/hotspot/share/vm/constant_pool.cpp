//
// Created by zhengzhipeng on 2021/6/8.
//

#include "../../../../../../../include/constant_pool.h"

void constant_pool::addItem(int tag, int index, void *val) {
    constant_pool::tag[index] = tag;
    constant_pool::data_map[index] = val;
}

constant_pool::constant_pool(class klass *_klass, int len) {
    constant_pool::len = len;
    constant_pool::klass = _klass;
}

int *constant_pool::getTag() const {
    return tag;
}

void constant_pool::setTag(int *tag) {
    constant_pool::tag = tag;
}

const map<int, void *> &constant_pool::getDataMap() const {
    return data_map;
}

void constant_pool::setDataMap(const map<int, void *> &dataMap) {
    data_map = dataMap;
}

int constant_pool::getLen() const {
    return len;
}

void constant_pool::setLen(int len) {
    constant_pool::len = len;
}

klass *constant_pool::getKlass() const {
    return klass;
}

void constant_pool::setKlass(class klass *klass) {
    constant_pool::klass = klass;
}



