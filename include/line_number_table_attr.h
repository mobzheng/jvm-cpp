//
// Created by zhengzhipeng on 2021/6/8.
//

#ifndef JVM_CPP_LINE_NUMBER_TABLE_ATTR_H
#define JVM_CPP_LINE_NUMBER_TABLE_ATTR_H
#include "attribute_info.h"
#include "line_number_table.h"

class line_number_table_attr:public attribute_info {

private:
    int attr_name_index;
    int attr_len;
    int line_num_len;
    line_number_table **lineNumberTable;

public:
    int getAttrNameIndex() const;

    void setAttrNameIndex(int attrNameIndex);

    int getAttrLen() const;

    void setAttrLen(int attrLen);

    int getLineNumLen() const;

    void setLineNumLen(int lineNumLen);

    line_number_table **getLineNumberTable() const;

    void setLineNumberTable(line_number_table **lineNumberTable);
};


#endif //JVM_CPP_LINE_NUMBER_TABLE_ATTR_H
