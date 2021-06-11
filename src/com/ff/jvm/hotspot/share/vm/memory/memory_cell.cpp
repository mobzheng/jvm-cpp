//
// Created by zhengzhipeng on 2021/6/10.
//

#include "../../../../../../../../include/memory_cell.h"

int memory_cell::getStart() const {
    return start;
}

void memory_cell::setStart(int start) {
    memory_cell::start = start;
}

int memory_cell::getSize() const {
    return size;
}

void memory_cell::setSize(int size) {
    memory_cell::size = size;
}

int memory_cell::getFree() const {
    return free;
}

void memory_cell::setFree(int free) {
    memory_cell::free = free;
}


