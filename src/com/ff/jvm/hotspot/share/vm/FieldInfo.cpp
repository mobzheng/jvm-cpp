//
// Created by zhengzhipeng on 2021/6/8.
//

#include "../../../../../../../include/FieldInfo.h"

int FieldInfo::getClassIndex() const {
    return class_index;
}

void FieldInfo::setClassIndex(int classIndex) {
    class_index = classIndex;
}

int FieldInfo::getNameTypeIndex() const {
    return name_type_index;
}

void FieldInfo::setNameTypeIndex(int nameTypeIndex) {
    name_type_index = nameTypeIndex;
}
