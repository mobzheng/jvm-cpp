//
// Created by ff on 2021/6/7.
//

#include "../../../../../../../include/methodInfo.h"

int methodInfo::getAccessFlags() const {
    return accessFlags;
}

void methodInfo::setAccessFlags(int accessFlags) {
    methodInfo::accessFlags = accessFlags;
}

int methodInfo::getNameIndex() const {
    return nameIndex;
}

void methodInfo::setNameIndex(int nameIndex) {
    methodInfo::nameIndex = nameIndex;
}

int methodInfo::getDesindex() const {
    return desindex;
}

void methodInfo::setDesindex(int desindex) {
    methodInfo::desindex = desindex;
}

attribute_info *methodInfo::getAAttributeInfo() const {
    return aAttributeInfo;
}

void methodInfo::setAAttributeInfo(attribute_info *aAttributeInfo) {
    methodInfo::aAttributeInfo = aAttributeInfo;
}

int methodInfo::getAttrCount() const {
    return attrCount;
}

void methodInfo::setAttrCount(int attrCount) {
    methodInfo::attrCount = attrCount;
}
