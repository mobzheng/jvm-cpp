//
// Created by zhengzhipeng on 2021/6/8.
//

#ifndef JVM_CPP_BYTEUTILS_H
#define JVM_CPP_BYTEUTILS_H
#include "mm_malloc.h"
#include "common.h"
class ByteUtils {

    void arrayCopy(byte *src, int src_pos, byte *des,int des_pos,int len);

};


#endif //JVM_CPP_BYTEUTILS_H
