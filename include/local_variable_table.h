//
// Created by zhengzhipeng on 2021/6/11.
//

#ifndef JVM_CPP_LOCAL_VARIABLE_TABLE_H
#define JVM_CPP_LOCAL_VARIABLE_TABLE_H


class local_variable_table {

private:
    int start_pc;
    int len;
    int name_index;
    int descriptor_index;
    int index;
public:
    int getStartPc() const;

    void setStartPc(int startPc);

    int getLen() const;

    void setLen(int len);

    int getNameIndex() const;

    void setNameIndex(int nameIndex);

    int getDescriptorIndex() const;

    void setDescriptorIndex(int descriptorIndex);

    int getIndex() const;

    void setIndex(int index);
};


#endif //JVM_CPP_LOCAL_VARIABLE_TABLE_H
