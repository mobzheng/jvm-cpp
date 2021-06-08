//
// Created by zhengzhipeng on 2021/6/8.
//

#ifndef JVM_CPP_LINENUMBERTABLEATTR_H
#define JVM_CPP_LINENUMBERTABLEATTR_H
#include "AttributeInfo.h"
#include "LineNumberTable.h"

class LineNumberTableAttr:public AttributeInfo {

private:
    int attr_name_index;
    int attr_len;
    int line_num_len;
    LineNumberTable **lineNumberTable;

public:
    int getAttrNameIndex() const;

    void setAttrNameIndex(int attrNameIndex);

    int getAttrLen() const;

    void setAttrLen(int attrLen);

    int getLineNumLen() const;

    void setLineNumLen(int lineNumLen);

    LineNumberTable **getLineNumberTable() const;

    void setLineNumberTable(LineNumberTable **lineNumberTable);
};


#endif //JVM_CPP_LINENUMBERTABLEATTR_H
