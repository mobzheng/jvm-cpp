//
// Created by zhengzhipeng on 2021/6/8.
//

#ifndef JVM_CPP_CONSTANT_POOL_H
#define JVM_CPP_CONSTANT_POOL_H

#include <map>
#include<string>
#include"common.h"
#include "klass.h"

using namespace std;

class klass;

class constant_pool {
private:
    int *tag;
    map<int, void *> data_map;
    int len;
    klass *klass;


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


    constant_pool(class klass *_klass, int len);


    void addItem(int tag, int index, void *val);

    int *getTag() const;

    void setTag(int *tag);

    const map<int, void *> &getDataMap() const;

    void setDataMap(const map<int, void *> &dataMap);

    int getLen() const;

    void setLen(int len);

    class klass *getKlass() const;

    void setKlass(class klass *klass);;

};


#endif //JVM_CPP_CONSTANT_POOL_H
