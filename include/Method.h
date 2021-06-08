//
// Created by zhengzhipeng on 2021/6/8.
//

#ifndef JVM_CPP_METHOD_H
#define JVM_CPP_METHOD_H
#include "common.h"
#include "AttributeInfo.h"

class Method {
private:
    int access_flags;
    int name_index;
    int des_index;
    int attr_conunt;
    AttributeInfo ** attribute;
public:
    int getAccessFlags() const;

    void setAccessFlags(int accessFlags);

    int getNameIndex() const;

    void setNameIndex(int nameIndex);

    int getDesIndex() const;

    void setDesIndex(int desIndex);

    int getAttrConunt() const;

    void setAttrConunt(int attrConunt);

    AttributeInfo **getAttribute() const;

    void setAttribute(AttributeInfo **attribute);
};


#endif //JVM_CPP_METHOD_H
