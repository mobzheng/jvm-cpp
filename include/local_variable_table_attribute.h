//
// Created by zhengzhipeng on 2021/6/11.
//

#ifndef JVM_CPP_LOCAL_VARIABLE_TABLE_ATTRIBUTE_H
#define JVM_CPP_LOCAL_VARIABLE_TABLE_ATTRIBUTE_H


#include "local_variable_table.h"

class local_variable_table_attribute {

private:
    int attr_name_index;
    int attr_len;
    int local_variable_len;
    local_variable_table **pVariableTable;
public:
    int getAttrNameIndex() const;

    void setAttrNameIndex(int attrNameIndex);

    int getAttrLen() const;

    void setAttrLen(int attrLen);

    int getLocalVariableLen() const;

    void setLocalVariableLen(int localVariableLen);

    local_variable_table **getPVariableTable() const;

    void setPVariableTable(local_variable_table **pVariableTable);
};


#endif //JVM_CPP_LOCAL_VARIABLE_TABLE_ATTRIBUTE_H
