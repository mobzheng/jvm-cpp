//
// Created by zhengzhipeng on 2021/6/9.
//

#ifndef JVM_CPP_CODEATTR_H
#define JVM_CPP_CODEATTR_H


#include "common.h"
#include "AttributeInfo.h"
#include "ExeceptionTable.h"
#include <string>
#include <map>
using namespace std;
class CodeAttr {
private:
    int attr_name_index;
    int attr_len;
    int max_stack;
    int max_locals;
    int code_len;
    byte* code;
    int exception_table_len;
    ExeceptionTable* execeptionTable;
    int attr_count;
    map<string,AttributeInfo> attributeInfomap;
public:
    int getAttrNameIndex() const;

    void setAttrNameIndex(int attrNameIndex);

    int getAttrLen() const;

    void setAttrLen(int attrLen);

    int getMaxStack() const;

    void setMaxStack(int maxStack);

    int getMaxLocals() const;

    void setMaxLocals(int maxLocals);

    int getCodeLen() const;

    void setCodeLen(int codeLen);

    byte *getCode() const;

    void setCode(byte *code);

    int getExceptionTableLen() const;

    void setExceptionTableLen(int exceptionTableLen);

    ExeceptionTable *getExeceptionTable() const;

    void setExeceptionTable(ExeceptionTable *execeptionTable);

    int getAttrCount() const;

    void setAttrCount(int attrCount);

    const map<string, AttributeInfo> &getAttributeInfomap() const;

    void setAttributeInfomap(const map<string, AttributeInfo> &attributeInfomap);

};


#endif //JVM_CPP_CODEATTR_H
