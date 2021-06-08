//
// Created by zhengzhipeng on 2021/6/8.
//

#ifndef JVM_CPP_LINENUMBERTABLE_H
#define JVM_CPP_LINENUMBERTABLE_H


class LineNumberTable {
private:
    int start_pc;
    int line_number;
public:
    int getStartPc() const;

    void setStartPc(int startPc);

    int getLineNumber() const;

    void setLineNumber(int lineNumber);

};


#endif //JVM_CPP_LINENUMBERTABLE_H
