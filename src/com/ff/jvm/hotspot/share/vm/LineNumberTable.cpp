//
// Created by zhengzhipeng on 2021/6/8.
//

#include "../../../../../../../include/LineNumberTable.h"

int LineNumberTable::getStartPc() const {
    return start_pc;
}

void LineNumberTable::setStartPc(int startPc) {
    start_pc = startPc;
}

int LineNumberTable::getLineNumber() const {
    return line_number;
}

void LineNumberTable::setLineNumber(int lineNumber) {
    line_number = lineNumber;
}
