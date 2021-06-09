//
// Created by zhengzhipeng on 2021/6/8.
//

#ifndef JVM_CPP_METHOD_H
#define JVM_CPP_METHOD_H

#include "common.h"
#include "AttributeInfo.h"
#include "CodeAttr.h"
#include <map>

using namespace std;

class Method {
private:
    int access_flags;
    int name_index;
    int des_index;
    int attr_count;
    CodeAttr **codeInfos;


public:
    int getAccessFlags() const;

    void setAccessFlags(int accessFlags);

    int getNameIndex() const;

    void setNameIndex(int nameIndex);

    int getDesIndex() const;

    void setDesIndex(int desIndex);

    int getAttrCount() const;

    void setAttrCount(int attrCount);

    CodeAttr **getCodeInfos() const;

    void setCodeInfos(CodeAttr **codeInfos);

};


#endif //JVM_CPP_METHOD_H
