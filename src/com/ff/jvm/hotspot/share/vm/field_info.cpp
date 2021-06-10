//
// Created by zhengzhipeng on 2021/6/8.
//

#include "../../../../../../../include/field_info.h"

int field_info::getAccessFlags() const {
    return accessFlags;
}

void field_info::setAccessFlags(int accessFlags) {
    field_info::accessFlags = accessFlags;
}

int field_info::getNameIndex() const {
    return nameIndex;
}

void field_info::setNameIndex(int nameIndex) {
    field_info::nameIndex = nameIndex;
}

int field_info::getDescriptorIndex() const {
    return descriptorIndex;
}

void field_info::setDescriptorIndex(int descriptorIndex) {
    field_info::descriptorIndex = descriptorIndex;
}

int field_info::getAttributesCount() const {
    return attributesCount;
}

void field_info::setAttributesCount(int attributesCount) {
    field_info::attributesCount = attributesCount;
}
