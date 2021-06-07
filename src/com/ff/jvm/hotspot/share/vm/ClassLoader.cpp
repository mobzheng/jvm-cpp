//
// Created by zhengzhipeng on 2021/6/7.
//

#include "../../../../../../../include/ClassLoader.h"

void ClassLoader::loadClass(char *className) {
    FILE *file = fopen(className, "rb");
    if (file == NULL) {
        printf("文件打开失败");
    }
////
//    fseek(file, 0, SEEK_END);
//    int len = ftell(file);
//    fseek(file, 0, SEEK_SET);

//    byte *bytes = {0};

    byte *bytes;
    int index = 0;
    while (1) {
        byte c = getc(file);
        printf("c = %d\n", c);
        if (feof(file)) {
            break;
        }
        bytes[index++] = c;
    }
    parseKlass(new Reader(bytes));
    printf("解析完毕");
}


Klass *ClassLoader::parseKlass(Reader *reader) {

    byte *arru4 = (byte*) malloc(4*sizeof(byte));
    reader->readU4(arru4);
    Klass *klass = new Klass;
    klass->setMagic(arru4);
    byte *arru2 = (byte *) malloc(sizeof(byte)*2);
    reader->readU2(arru2);
    klass->setMajorVersion(arru2);
    reader->readU2(arru2);
    klass->setMinorVersion(arru2);
    return nullptr;
}
