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

int Method::getAttrConunt() const {
    return attr_conunt;
}

void Method::setAttrConunt(int attrConunt) {
    attr_conunt = attrConunt;
}

AttributeInfo **Method::getAttribute() const {
    return attribute;
}

void Method::setAttribute(AttributeInfo **attribute) {
    Method::attribute = attribute;
}

