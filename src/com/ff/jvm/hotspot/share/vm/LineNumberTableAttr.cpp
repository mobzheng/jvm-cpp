//
// Created by zhengzhipeng on 2021/6/8.
//

#include "../../../../../../../include/LineNumberTableAttr.h"

int LineNumberTableAttr::getAttrNameIndex() const {
    return attr_name_index;
}

void LineNumberTableAttr::setAttrNameIndex(int attrNameIndex) {
    attr_name_index = attrNameIndex;
}

int LineNumberTableAttr::getAttrLen() const {
    return attr_len;
}

void LineNumberTableAttr::setAttrLen(int attrLen) {
    attr_len = attrLen;
}

int LineNumberTableAttr::getLineNumLen() const {
    return line_num_len;
}

void LineNumberTableAttr::setLineNumLen(int lineNumLen) {
    line_num_len = lineNumLen;
}

LineNumberTable **LineNumberTableAttr::getLineNumberTable() const {
    return lineNumberTable;
}

void LineNumberTableAttr::setLineNumberTable(LineNumberTable **lineNumberTable) {
    LineNumberTableAttr::lineNumberTable = lineNumberTable;
}
