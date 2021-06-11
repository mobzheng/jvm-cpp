//
// Created by zhengzhipeng on 2021/6/11.
//

#include "../../../../../../../include/local_variable_table_attribute.h"

int local_variable_table_attribute::getAttrNameIndex() const {
    return attr_name_index;
}

void local_variable_table_attribute::setAttrNameIndex(int attrNameIndex) {
    attr_name_index = attrNameIndex;
}

int local_variable_table_attribute::getAttrLen() const {
    return attr_len;
}

void local_variable_table_attribute::setAttrLen(int attrLen) {
    attr_len = attrLen;
}

int local_variable_table_attribute::getLocalVariableLen() const {
    return local_variable_len;
}

void local_variable_table_attribute::setLocalVariableLen(int localVariableLen) {
    local_variable_len = localVariableLen;
}

local_variable_table **local_variable_table_attribute::getPVariableTable() const {
    return pVariableTable;
}

void local_variable_table_attribute::setPVariableTable(local_variable_table **pVariableTable) {
    local_variable_table_attribute::pVariableTable = pVariableTable;
}
