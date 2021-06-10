//
// Created by zhengzhipeng on 2021/6/8.
//

#ifndef JVM_CPP_METHOD_H
#define JVM_CPP_METHOD_H

#include "common.h"
#include "attribute_info.h"
#include "code_attr.h"
#include <map>

using namespace std;

class method {
private:
    int access_flags;
    int name_index;
    int des_index;
    int attr_count;
    code_attr **codeInfos;


public:
    int getAccessFlags() const;

    void setAccessFlags(int accessFlags);

    int getNameIndex() const;

    void setNameIndex(int nameIndex);

    int getDesIndex() const;

    void setDesIndex(int desIndex);

    int getAttrCount() const;

    void setAttrCount(int attrCount);

    code_attr **getCodeInfos() const;

    void setCodeInfos(code_attr **codeInfos);

};


#endif //JVM_CPP_METHOD_H
