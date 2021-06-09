//
// Created by zhengzhipeng on 2021/6/9.
//

#include "../../../../../../../include/CodeAttr.h"

int CodeAttr::getAttrNameIndex() const {
    return attr_name_index;
}

void CodeAttr::setAttrNameIndex(int attrNameIndex) {
    attr_name_index = attrNameIndex;
}

int CodeAttr::getAttrLen() const {
    return attr_len;
}

void CodeAttr::setAttrLen(int attrLen) {
    attr_len = attrLen;
}

int CodeAttr::getMaxStack() const {
    return max_stack;
}

void CodeAttr::setMaxStack(int maxStack) {
    max_stack = maxStack;
}

int CodeAttr::getMaxLocals() const {
    return max_locals;
}

void CodeAttr::setMaxLocals(int maxLocals) {
    max_locals = maxLocals;
}

int CodeAttr::getCodeLen() const {
    return code_len;
}

void CodeAttr::setCodeLen(int codeLen) {
    code_len = codeLen;
}

byte *CodeAttr::getCode() const {
    return code;
}

void CodeAttr::setCode(byte *code) {
    CodeAttr::code = code;
}



ExeceptionTable *CodeAttr::getExeceptionTable() const {
    return execeptionTable;
}

void CodeAttr::setExeceptionTable(ExeceptionTable *execeptionTable) {
    CodeAttr::execeptionTable = execeptionTable;
}

int CodeAttr::getAttrCount() const {
    return attr_count;
}

void CodeAttr::setAttrCount(int attrCount) {
    attr_count = attrCount;
}

const map<string, AttributeInfo> &CodeAttr::getAttributeInfomap() const {
    return attributeInfomap;
}

void CodeAttr::setAttributeInfomap(const map<string, AttributeInfo> &attributeInfomap) {
    CodeAttr::attributeInfomap = attributeInfomap;
}

int CodeAttr::getExceptionTableLen() const {
    return exception_table_len;
}

void CodeAttr::setExceptionTableLen(int exceptionTableLen) {
    exception_table_len = exceptionTableLen;
}
