//
// Created by zhengzhipeng on 2021/6/8.
//

#include "../../../../../../../include/method.h"

int method::getAccessFlags() const {
    return access_flags;
}

void method::setAccessFlags(int accessFlags) {
    access_flags = accessFlags;
}

int method::getNameIndex() const {
    return name_index;
}

void method::setNameIndex(int nameIndex) {
    name_index = nameIndex;
}

int method::getDesIndex() const {
    return des_index;
}

void method::setDesIndex(int desIndex) {
    des_index = desIndex;
}



int method::getAttrCount() const {
    return attr_count;
}

void method::setAttrCount(int attrCount) {
    attr_count = attrCount;
}

code_attr **method::getCodeInfos() const {
    return codeInfos;
}

void method::setCodeInfos(code_attr **codeInfos) {
    method::codeInfos = codeInfos;
}



