//
// Created by zhengzhipeng on 2021/6/8.
//

#ifndef JVM_CPP_CONSTANTPOOL_H
#define JVM_CPP_CONSTANTPOOL_H

#include <map>
#include<string>
#include"common.h"
#include "Klass.h"

using namespace std;

class Klass;

class ConstantPool {
private:
    int *tag;
    map<int, byte *> datamap;
    int len;
    Klass *klass;


public:
    static const int JVM_CONSTANT_Utf8 = 1;
    static const int JVM_CONSTANT_Unicode = 2;   /* unused */
    static const int JVM_CONSTANT_Integer = 3;
    static const int JVM_CONSTANT_Float = 4;
    static const int JVM_CONSTANT_Long = 5;
    static const int JVM_CONSTANT_Double = 6;
    static const int JVM_CONSTANT_Class = 7;
    static const int JVM_CONSTANT_String = 8;
    static const int JVM_CONSTANT_Fieldref = 9;
    static const int JVM_CONSTANT_Methodref = 10;
    static const int JVM_CONSTANT_InterfaceMethodref = 11;
    static const int JVM_CONSTANT_NameAndType = 12;
    static const int JVM_CONSTANT_MethodHandle = 15; /* JSR 292 */
    static const int JVM_CONSTANT_MethodType = 16;   /* JSR 292 */
    static const int JVM_CONSTANT_InvokeDynamic = 18;    /* JSR 292 */
    static const int JVM_CONSTANT_ExternalMax = 18;


    ConstantPool(Klass *_klass);

    int *getTag();

    void setTag(int *tag);

    const map<int, byte *> &getDatamap() const;

    void setDatamap(const map<int, byte *> &datamap);

    int getLen() const;

    void setLen(int len);

    void addItem(int tag, int index, byte *val);

};


#endif //JVM_CPP_CONSTANTPOOL_H
