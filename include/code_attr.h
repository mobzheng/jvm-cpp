//
// Created by zhengzhipeng on 2021/6/9.
//

#ifndef JVM_CPP_CODE_ATTR_H
#define JVM_CPP_CODE_ATTR_H


#include "common.h"
#include "attribute_info.h"
#include "exeception_table.h"
#include <string>
#include <map>
using namespace std;

class code_attr {
private:
    int attr_name_index;
    int attr_len;
    int max_stack;
    int max_locals;
    int code_len;
    byte* code;
    int exception_table_len;
    exeception_table* execeptionTable;
    int attr_count;
    map<string,attribute_info> attributeInfomap;
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

    exeception_table *getExeceptionTable() const;

    void setExeceptionTable(exeception_table *execeptionTable);

    int getAttrCount() const;

    void setAttrCount(int attrCount);

    const map<string, attribute_info> &getAttributeInfomap() const;

    void setAttributeInfomap(const map<string, attribute_info> &attributeInfomap);

};


#endif //JVM_CPP_CODE_ATTR_H
