//
// Created by zhengzhipeng on 2021/6/7.
//

#ifndef JVM_CPP_CLASSLOADER_H
#define JVM_CPP_CLASSLOADER_H
#include <string>
#include "Reader.h"
class ClassLoader {
public:
    void loadClass(char *className);

};


#endif //JVM_CPP_CLASSLOADER_H
