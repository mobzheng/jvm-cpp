//
// Created by zhengzhipeng on 2021/6/11.
//

#include "../../../../../../../include/local_variable_table.h"

int local_variable_table::getStartPc() const {
    return start_pc;
}

void local_variable_table::setStartPc(int startPc) {
    start_pc = startPc;
}

int local_variable_table::getLen() const {
    return len;
}

void local_variable_table::setLen(int len) {
    local_variable_table::len = len;
}

int local_variable_table::getNameIndex() const {
    return name_index;
}

void local_variable_table::setNameIndex(int nameIndex) {
    name_index = nameIndex;
}

int local_variable_table::getDescriptorIndex() const {
    return descriptor_index;
}

void local_variable_table::setDescriptorIndex(int descriptorIndex) {
    descriptor_index = descriptorIndex;
}

int local_variable_table::getIndex() const {
    return index;
}

void local_variable_table::setIndex(int index) {
    local_variable_table::index = index;
}
