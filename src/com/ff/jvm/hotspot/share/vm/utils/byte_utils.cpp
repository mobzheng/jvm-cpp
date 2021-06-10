//
// Created by zhengzhipeng on 2021/6/8.
//

#include "../../../../../../../../include/byte_utils.h"

void byte_utils::arrayCopy(byte *src, int src_pos, byte *des, int des_pos, int len) {

    for (int i = 0; i < len; ++i) {
        des[des_pos++] = src[src_pos++];
    }
}
