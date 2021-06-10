//
// Created by zhengzhipeng on 2021/6/8.
//

#ifndef JVM_CPP_FIELD_INFO_H
#define JVM_CPP_FIELD_INFO_H


class field_info {

private:
    int accessFlags;
    int nameIndex;
    int descriptorIndex;
    int attributesCount;

public:
    int getAccessFlags() const;

    void setAccessFlags(int accessFlags);

    int getNameIndex() const;

    void setNameIndex(int nameIndex);

    int getDescriptorIndex() const;

    void setDescriptorIndex(int descriptorIndex);

    int getAttributesCount() const;

    void setAttributesCount(int attributesCount);
};


#endif //JVM_CPP_FIELD_INFO_H
