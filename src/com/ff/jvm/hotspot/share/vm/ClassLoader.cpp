//
// Created by zhengzhipeng on 2021/6/7.
//

#include "../../../../../../../include/ClassLoader.h"

void ClassLoader::loadClass(char *className) {
    FILE *file = fopen(className, "rb");
    if (file==NULL)
    {
        printf("文件打开失败");
    }
    byte * bytes;
    int index = 0;
    while (1){
        byte c = getc(file);
//        printf("c = %d\n", c);
        if (feof(file))
        {
            break;
        }
        bytes[index++] = c;
    }
    Reader *reader = new Reader(bytes);
    byte* u1arr;
    reader->readU1(&u1arr);
    printf("读取到 u1arr[0] = %d", *u1arr);
    printf("解析完毕");
}
