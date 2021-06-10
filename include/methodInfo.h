//
// Created by ff on 2021/6/7.
//

#ifndef JVM_CPP_METHODINFO_H
#define JVM_CPP_METHODINFO_H
#include "common.h"
#include "attribute_info.h"
class methodInfo {
private:
    int accessFlags;
    int nameIndex;
    int desindex;
    int attrCount;
    attribute_info* aAttributeInfo;

public:

    int getAttrCount() const;

    void setAttrCount(int attrCount);

    int getAccessFlags() const;

    void setAccessFlags(int accessFlags);

    int getNameIndex() const;

    void setNameIndex(int nameIndex);

    int getDesindex() const;

    void setDesindex(int desindex);

    attribute_info *getAAttributeInfo() const;

    void setAAttributeInfo(attribute_info *aAttributeInfo);

};


#endif //JVM_CPP_METHODINFO_H
