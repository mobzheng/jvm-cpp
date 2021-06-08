//
// Created by ff on 2021/6/7.
//

#ifndef JVM_CPP_METHODINFO_H
#define JVM_CPP_METHODINFO_H
#include "common.h"
#include "AttributeInfo.h"
class MethodInfo {
private:
    int accessFlags;
    int nameIndex;
    int desindex;
    int attrCount;
    AttributeInfo* aAttributeInfo;

public:

    int getAttrCount() const;

    void setAttrCount(int attrCount);

    int getAccessFlags() const;

    void setAccessFlags(int accessFlags);

    int getNameIndex() const;

    void setNameIndex(int nameIndex);

    int getDesindex() const;

    void setDesindex(int desindex);

    AttributeInfo *getAAttributeInfo() const;

    void setAAttributeInfo(AttributeInfo *aAttributeInfo);

};


#endif //JVM_CPP_METHODINFO_H
