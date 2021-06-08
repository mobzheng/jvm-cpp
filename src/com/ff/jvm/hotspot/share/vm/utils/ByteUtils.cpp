//
// Created by zhengzhipeng on 2021/6/8.
//

#include "../../../../../../../../include/ByteUtils.h"

void ByteUtils::arrayCopy(byte *src, int src_pos, byte *des, int des_pos, int len) {

    for (int i = 0; i < len; ++i) {
        des[des_pos++] = src[src_pos++];
    }
}
