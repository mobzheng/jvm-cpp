//
// Created by zhengzhipeng on 2021/6/8.
//

#include "../../../../../../../include/Method.h"

int Method::getAccessFlags() const {
    return access_flags;
}

void Method::setAccessFlags(int accessFlags) {
    access_flags = accessFlags;
}

int Method::getNameIndex() const {
    return name_index;
}

void Method::setNameIndex(int nameIndex) {
    name_index = nameIndex;
}

int Method::getDesIndex() const {
    return des_index;
}

void Method::setDesIndex(int desIndex) {
    des_index = desIndex;
}



int Method::getAttrCount() const {
    return attr_count;
}

void Method::setAttrCount(int attrCount) {
    attr_count = attrCount;
}

CodeAttr **Method::getCodeInfos() const {
    return codeInfos;
}

void Method::setCodeInfos(CodeAttr **codeInfos) {
    Method::codeInfos = codeInfos;
}



