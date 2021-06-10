//
// Created by zhengzhipeng on 2021/6/8.
//

#include "../../../../../../../include/line_number_table.h"

int line_number_table::getStartPc() const {
    return start_pc;
}

void line_number_table::setStartPc(int startPc) {
    start_pc = startPc;
}

int line_number_table::getLineNumber() const {
    return line_number;
}

void line_number_table::setLineNumber(int lineNumber) {
    line_number = lineNumber;
}
