//
// Created by zhengzhipeng on 2021/6/8.
//

#include "../../../../../../../include/FieldInfo.h"

int FieldInfo::getAccessFlags() const {
    return accessFlags;
}

void FieldInfo::setAccessFlags(int accessFlags) {
    FieldInfo::accessFlags = accessFlags;
}

int FieldInfo::getNameIndex() const {
    return nameIndex;
}

void FieldInfo::setNameIndex(int nameIndex) {
    FieldInfo::nameIndex = nameIndex;
}

int FieldInfo::getDescriptorIndex() const {
    return descriptorIndex;
}

void FieldInfo::setDescriptorIndex(int descriptorIndex) {
    FieldInfo::descriptorIndex = descriptorIndex;
}

int FieldInfo::getAttributesCount() const {
    return attributesCount;
}

void FieldInfo::setAttributesCount(int attributesCount) {
    FieldInfo::attributesCount = attributesCount;
}
