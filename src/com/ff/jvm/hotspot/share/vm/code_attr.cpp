//
// Created by zhengzhipeng on 2021/6/9.
//

#include "../../../../../../../include/code_attr.h"

int code_attr::getAttrNameIndex() const {
    return attr_name_index;
}

void code_attr::setAttrNameIndex(int attrNameIndex) {
    attr_name_index = attrNameIndex;
}

int code_attr::getAttrLen() const {
    return attr_len;
}

void code_attr::setAttrLen(int attrLen) {
    attr_len = attrLen;
}

int code_attr::getMaxStack() const {
    return max_stack;
}

void code_attr::setMaxStack(int maxStack) {
    max_stack = maxStack;
}

int code_attr::getMaxLocals() const {
    return max_locals;
}

void code_attr::setMaxLocals(int maxLocals) {
    max_locals = maxLocals;
}

int code_attr::getCodeLen() const {
    return code_len;
}

void code_attr::setCodeLen(int codeLen) {
    code_len = codeLen;
}

byte *code_attr::getCode() const {
    return code;
}

void code_attr::setCode(byte *code) {
    code_attr::code = code;
}



exeception_table *code_attr::getExeceptionTable() const {
    return execeptionTable;
}

void code_attr::setExeceptionTable(exeception_table *execeptionTable) {
    code_attr::execeptionTable = execeptionTable;
}

int code_attr::getAttrCount() const {
    return attr_count;
}

void code_attr::setAttrCount(int attrCount) {
    attr_count = attrCount;
}

const map<string, attribute_info> &code_attr::getAttributeInfomap() const {
    return attributeInfomap;
}

void code_attr::setAttributeInfomap(const map<string, attribute_info> &attributeInfomap) {
    code_attr::attributeInfomap = attributeInfomap;
}

int code_attr::getExceptionTableLen() const {
    return exception_table_len;
}

void code_attr::setExceptionTableLen(int exceptionTableLen) {
    exception_table_len = exceptionTableLen;
}
