//
// Created by zhengzhipeng on 2021/6/8.
//

#include "../../../../../../../include/line_number_table_attr.h"

int line_number_table_attr::getAttrNameIndex() const {
    return attr_name_index;
}

void line_number_table_attr::setAttrNameIndex(int attrNameIndex) {
    attr_name_index = attrNameIndex;
}

int line_number_table_attr::getAttrLen() const {
    return attr_len;
}

void line_number_table_attr::setAttrLen(int attrLen) {
    attr_len = attrLen;
}

int line_number_table_attr::getLineNumLen() const {
    return line_num_len;
}

void line_number_table_attr::setLineNumLen(int lineNumLen) {
    line_num_len = lineNumLen;
}

line_number_table **line_number_table_attr::getLineNumberTable() const {
    return lineNumberTable;
}

void line_number_table_attr::setLineNumberTable(line_number_table **lineNumberTable) {
    line_number_table_attr::lineNumberTable = lineNumberTable;
}
