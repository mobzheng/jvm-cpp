//
// Created by zhengzhipeng on 2021/6/7.
//

#include "../../../../../../../include/ClassLoader.h"
#include "../../../../../../../include/AttributeInfo.h"
#include "../../../../../../../include/LineNumberTableAttr.h"

void ClassLoader::loadClass(char *className) {
    FILE *file = fopen(className, "rb");
    if (file == NULL) {
        printf("文件打开失败");
    }
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
    Klass *klass = new Klass;
    // 魔数
    klass->setMagic(reader->readU4());
    // 次版本号
    klass->setMinorVersion(reader->readU2());
    // 主版本号
    klass->setMajorVersion(reader->readU2());
    // 常量池大小
    ConstantPool *constantPool = new ConstantPool(klass);
//    constantPool->setKlass();
    constantPool->setLen(reader->readU2Simple());
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
    map<int, byte *> datamap = pPool->getDatamap();
    int len = pPool->getLen();
    int *tags = (int *) malloc(sizeof(int) * len);
    pPool->setTag(tags);

    for (int i = 1; i < len; ++i) {
        int tag = pReader->readU1Simple();
        switch (tag) {
            case ConstantPool::JVM_CONSTANT_Class:
                tags[i] = tag;
                pReader->readU2Simple();
                break;
            case ConstantPool::JVM_CONSTANT_Utf8: {
                tags[i] = tag;
                int str_len = pReader->readU2Simple();
                byte *str = pReader->read(str_len);
                printf("读取到的字符串 str = %s\n", str);
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
            case ConstantPool::JVM_CONSTANT_NameAndType:
            {
                byte *name_type = (byte*) malloc(sizeof(byte));
                name_type[0] = pReader->readU2Simple();
                name_type[1] = pReader->readU2Simple();
                pPool->addItem(tag, i, name_type);
            }
                break;
            default:
                printf("未支持的类型 tag = %d index = %d  上一个 tag = %d", tag, i, tags[i - 1]);
                exit(0);
        }
        printf("常量池解析完毕");

    }


}

void ClassLoader::parseInterface(Klass *pKlass, Reader *pReader) {
    for (int i = 0; i < pKlass->getInterfaceCount(); ++i) {
        Interface *interface = new Interface;
        interface->setNameIndex(pReader->readU2Simple());
        pKlass->getInterfaces()[i] = interface;
    }
}

void ClassLoader::parseField(Klass *pKlass, Reader *pReader) {
    for (int i = 0; i <pKlass->getFieldCount(); ++i) {
        FieldInfo* fieldInfo = new FieldInfo;
        fieldInfo->setNameTypeIndex(pReader->readU2Simple());
        fieldInfo->setClassIndex(pReader->readU2Simple());
        pKlass->getFieldInfos()[i] = fieldInfo;
    }

}

void ClassLoader::parseMethod(Klass *pKlass, Reader *pReader) {

    for (int i = 0; i < pKlass->getMethodCount(); ++i) {
        Method * method = new Method;
        pKlass->getMethods()[i] = method;
        method->setAccessFlags(pReader->readU2Simple());
        method->setNameIndex(pReader->readU2Simple());
        method->setDesIndex(pReader->readU2Simple());
        method->setAttrConunt(pReader->readU2Simple());
        method->setAttribute(parseMethodAttr(method, pReader));
    }
}

void ClassLoader::parseAttribute(Klass *pKlass, Reader *pReader) {

    int attr_index = pReader->readU2Simple();


}

AttributeInfo **ClassLoader::parseMethodAttr(Method *pMethod, Reader *pReader) {
    int attrConunt = pMethod->getAttrConunt();
    AttributeInfo **pAttributeInfo = (AttributeInfo**)malloc(sizeof(AttributeInfo*) * attrConunt);
    if (pAttributeInfo==NULL)
    {
        return NULL;
    }
    for (int i = 0; i < attrConunt; ++i) {
        LineNumberTableAttr* lineNumberTableAttr = new LineNumberTableAttr;
        lineNumberTableAttr->setAttrLen(pReader->readU2Simple());
        lineNumberTableAttr->setAttrLen(pReader->readU2Simple());
        lineNumberTableAttr->setLineNumLen(pReader->readU2Simple());
        for (int j = 0; j < lineNumberTableAttr->getLineNumLen(); ++j) {
            LineNumberTable * lineNumberTable =   new LineNumberTable;
            lineNumberTable->setStartPc(pReader->readU2Simple());
            lineNumberTable->setLineNumber(pReader->readU2Simple());
        }
    }
    return nullptr;
}
