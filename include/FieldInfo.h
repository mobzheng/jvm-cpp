//
// Created by zhengzhipeng on 2021/6/8.
//

#ifndef JVM_CPP_FIELDINFO_H
#define JVM_CPP_FIELDINFO_H


class FieldInfo {

private:
    int class_index;
    int name_type_index;


public:
    int getClassIndex() const;

    void setClassIndex(int classIndex);

    int getNameTypeIndex() const;

    void setNameTypeIndex(int nameTypeIndex);
};


#endif //JVM_CPP_FIELDINFO_H
