//
// Created by ff on 2021/6/7.
//

#include "../../../../../../../include/MethodInfo.h"

int MethodInfo::getAccessFlags() const {
    return accessFlags;
}

void MethodInfo::setAccessFlags(int accessFlags) {
    MethodInfo::accessFlags = accessFlags;
}

int MethodInfo::getNameIndex() const {
    return nameIndex;
}

void MethodInfo::setNameIndex(int nameIndex) {
    MethodInfo::nameIndex = nameIndex;
}

int MethodInfo::getDesindex() const {
    return desindex;
}

void MethodInfo::setDesindex(int desindex) {
    MethodInfo::desindex = desindex;
}

AttributeInfo *MethodInfo::getAAttributeInfo() const {
    return aAttributeInfo;
}

void MethodInfo::setAAttributeInfo(AttributeInfo *aAttributeInfo) {
    MethodInfo::aAttributeInfo = aAttributeInfo;
}

int MethodInfo::getAttrCount() const {
    return attrCount;
}

void MethodInfo::setAttrCount(int attrCount) {
    MethodInfo::attrCount = attrCount;
}
