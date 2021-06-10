//
// Created by zhengzhipeng on 2021/6/8.
//

#ifndef JVM_CPP_LINE_NUMBER_TABLE_H
#define JVM_CPP_LINE_NUMBER_TABLE_H


class line_number_table {
private:
    int start_pc;
    int line_number;
public:
    int getStartPc() const;

    void setStartPc(int startPc);

    int getLineNumber() const;

    void setLineNumber(int lineNumber);

};


#endif //JVM_CPP_LINE_NUMBER_TABLE_H
