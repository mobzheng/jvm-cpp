//
// Created by zhengzhipeng on 2021/6/7.
//

#include "../../../../../../../include/ClassLoader.h"

void ClassLoader::loadClass(char *className) {
    FILE *file = fopen(className, "rb");
    if (file == NULL) {
        printf("文件打开失败");
        exit(0);
    }
    byte *bytes;
    int index = 0;
    while (1) {
        byte c = getc(file);
        if (feof(file)) {
            break;
        }
        bytes[index++] = c;
    }
    parseKlass(new Reader(bytes, index));
}


Klass *ClassLoader::parseKlass(Reader *reader) {
    Klass *klass = new Klass;
    // 魔数
    klass->setMagic(reader->readU4());
    // 次版本号
    klass->setMinorVersion(reader->readU2());
    // 主版本号
    klass->setMajorVersion(reader->readU2());
    // 常量池大小
    ConstantPool *constantPool = new ConstantPool(klass,reader->readU2Simple());
    klass->setConstantPool(constantPool);
    parseConstantPool(constantPool, reader);

    klass->setAccessFlags(reader->readU2Simple());
    klass->setThisClass(reader->readU2Simple());
    klass->setSuperClass(reader->readU2Simple());

    klass->setInterfaceCount(reader->readU2Simple());
    parseInterface(klass, reader);

    klass->setFieldCount(reader->readU2Simple());
    parseField(klass, reader);

    klass->setMethodCount(reader->readU2Simple());
    parseMethod(klass, reader);

    klass->setAttributesCount(reader->readU2Simple());
    parseAttribute(klass, reader);
    return klass;
}

void ClassLoader::parseConstantPool(ConstantPool *pPool, Reader *pReader) {
    int len = pPool->getLen();
    int *tags = (int *) malloc(sizeof(int) * len);
    pPool->setTag(tags);

    for (int i = 1; i < len; ++i) {
        int tag = pReader->readU1Simple();
        switch (tag) {
            case ConstantPool::JVM_CONSTANT_Class:
                tags[i] = tag;
                pPool->addItem(tag, i, pReader->readU2());
                break;
            case ConstantPool::JVM_CONSTANT_Utf8: {
                tags[i] = tag;
                int str_len = pReader->readU2Simple();
                byte *str = pReader->read(str_len);
                pPool->addItem(tag, i, str);
                printf("读取到的字符串 index = %d str = %s\n", i, str);
            }
                break;
            case ConstantPool::JVM_CONSTANT_String: {

                pPool->addItem(tag, i, pReader->readU2());
            }
                break;
            case ConstantPool::JVM_CONSTANT_Methodref: {
                byte *method = (byte *) malloc(sizeof(byte) * 2);
                method[0] = pReader->readU2Simple();
                method[1] = pReader->readU2Simple();
                pPool->addItem(tag, i, method);
                printf("解析方法\n");
            }
                break;
            case ConstantPool::JVM_CONSTANT_Double: {
                tags[i] = tag;
                byte *double_info = pReader->readU8();
                pPool->addItem(tag, i++, double_info);
                pPool->addItem(tag, i, double_info);
            }
                break;
            case ConstantPool::JVM_CONSTANT_Fieldref: {
                byte *fieldinfo = (byte *) malloc(sizeof(byte) * 2);
                fieldinfo[0] = pReader->readU2Simple();
                fieldinfo[1] = pReader->readU2Simple();
                pPool->addItem(tag, i, fieldinfo);
            }
                break;
            case ConstantPool::JVM_CONSTANT_NameAndType: {
                byte *name_type = (byte *) malloc(sizeof(byte));
                name_type[0] = pReader->readU2Simple();
                name_type[1] = pReader->readU2Simple();
                pPool->addItem(tag, i, name_type);
            }
                break;
            default:
                printf("未支持的类型 tag = %d index = %d  上一个 tag = %d", tag, i, tags[i - 1]);
                exit(0);
        }

    }
    printf("常量池解析完毕\n");
    map<int, byte *> map = pPool->getDatamap();

    for (int i = 1; i <= map.size(); ++i) {
        printf("key = %d val = %s\n", i, map[i]);
    }


}

void ClassLoader::parseInterface(Klass *pKlass, Reader *pReader) {
    int interfaceCount = pKlass->getInterfaceCount();
    if (interfaceCount<1)
    {
        return;
    }
    for (int i = 0; i < interfaceCount; ++i) {
        Interface *interface = new Interface;
        interface->setNameIndex(pReader->readU2Simple());
        pKlass->getInterfaces()[i] = interface;
    }
}

void ClassLoader::parseField(Klass *pKlass, Reader *pReader) {
    pKlass->setFieldInfos((FieldInfo **) malloc(sizeof(FieldInfo *) * pKlass->getFieldCount()));
    for (int i = 0; i < pKlass->getFieldCount(); ++i) {
        FieldInfo *fieldInfo = new FieldInfo;
        pKlass->getFieldInfos()[i] = fieldInfo;
        fieldInfo->setAccessFlags(pReader->readU2Simple());
        fieldInfo->setNameIndex(pReader->readU2Simple());
        fieldInfo->setDescriptorIndex(pReader->readU2Simple());
        fieldInfo->setAttributesCount(pReader->readU2Simple());
    }

}

void ClassLoader::parseMethod(Klass *pKlass, Reader *pReader) {
    pKlass->setMethods((Method **) malloc(sizeof(Method **) * pKlass->getMethodCount()));
    for (int i = 0; i < pKlass->getMethodCount(); ++i) {
        Method *method = new Method;
        pKlass->getMethods()[i] = method;
        method->setAccessFlags(pReader->readU2Simple());
        method->setNameIndex(pReader->readU2Simple());
        method->setDesIndex(pReader->readU2Simple());
        method->setAttrCount(pReader->readU2Simple());
        parseMethodAttr(method, pReader, pKlass);
    }
}

void ClassLoader::parseAttribute(Klass *pKlass, Reader *pReader) {
    map<int,byte*> datamap = pKlass->getConstantPool()->getDatamap();

    int attr_index = pReader->readU2Simple();
    byte * name = datamap[attr_index];
    printf("name = %s", name);
}

CodeAttr ** ClassLoader::parseMethodAttr(Method *pMethod, Reader *pReader, Klass *klass) {
    int attrCount = pMethod->getAttrCount();
    if (attrCount<1)
    {
        return NULL;
    }
    CodeAttr **pCodeAttr = (CodeAttr **) malloc(sizeof(CodeAttr **) * attrCount);
    if (pCodeAttr == NULL) {
        return NULL;
    }
    CodeAttr *codeAttr = new CodeAttr;
    for (int i = 0; i < attrCount; ++i) {
        pCodeAttr[i] = codeAttr;
        codeAttr->setAttrNameIndex(pReader->readU2Simple());
        codeAttr->setAttrLen(pReader->readU4Simple());
        codeAttr->setMaxStack(pReader->readU2Simple());
        codeAttr->setMaxLocals(pReader->readU2Simple());
        codeAttr->setCodeLen(pReader->readU4Simple());
        codeAttr->setCode(pReader->read(codeAttr->getCodeLen()));
        codeAttr->setExceptionTableLen(pReader->readU2Simple());
        // todo 异常表解析
        codeAttr->setAttrCount(pReader->readU2Simple());
        parseAttribute(klass,pReader);


//        int tag = pReader->readU2Simple();
//        LineNumberTableAttr *lineNumberTableAttr = new LineNumberTableAttr;
//        lineNumberTableAttr->setAttrLen(pReader->readU2Simple());
//        lineNumberTableAttr->setAttrLen(pReader->readU2Simple());
//        lineNumberTableAttr->setLineNumLen(pReader->readU2Simple());
//        for (int j = 0; j < lineNumberTableAttr->getLineNumLen(); ++j) {
//            LineNumberTable *lineNumberTable = new LineNumberTable;
//            lineNumberTable->setStartPc(pReader->readU2Simple());
//            lineNumberTable->setLineNumber(pReader->readU2Simple());
//        }
    }
    return pCodeAttr;
}

