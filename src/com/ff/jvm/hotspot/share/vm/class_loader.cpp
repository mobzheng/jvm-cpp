//
// Created by zhengzhipeng on 2021/6/7.
//

#include "../../../../../../../include/class_loader.h"

void class_loader::loadClass(char *className) {
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
    parseKlass(new klass_reader(bytes, index));
}


klass *class_loader::parseKlass(klass_reader *reader) {
    klass *klass = new class klass;
    // 魔数
    klass->setMagic(reader->readU4());
    // 次版本号
    klass->setMinorVersion(reader->readU2());
    // 主版本号
    klass->setMajorVersion(reader->readU2());
    // 常量池大小
    constant_pool *constantPool = new constant_pool(klass,reader->readU2Simple());
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

void class_loader::parseConstantPool(constant_pool *pPool, klass_reader *pReader) {
    int len = pPool->getLen();
    int *tags = (int *) malloc(sizeof(int) * len);
    pPool->setTag(tags);

    for (int i = 1; i < len; ++i) {
        int tag = pReader->readU1Simple();
        switch (tag) {
            case constant_pool::JVM_CONSTANT_Class:
                tags[i] = tag;
                pPool->addItem(tag, i, pReader->readU2());
                break;
            case constant_pool::JVM_CONSTANT_Utf8: {
                tags[i] = tag;
                int str_len = pReader->readU2Simple();
                byte *str = pReader->read(str_len);
                pPool->addItem(tag, i, str);
                printf("读取到的字符串 index = %d str = %s\n", i, str);
            }
                break;
            case constant_pool::JVM_CONSTANT_String: {

                pPool->addItem(tag, i, pReader->readU2());
            }
                break;
            case constant_pool::JVM_CONSTANT_Methodref: {
                byte *method = (byte *) malloc(sizeof(byte) * 2);
                method[0] = pReader->readU2Simple();
                method[1] = pReader->readU2Simple();
                pPool->addItem(tag, i, method);
                printf("解析方法\n");
            }
                break;
            case constant_pool::JVM_CONSTANT_Double: {
                tags[i] = tag;
                byte *double_info = pReader->readU8();
                pPool->addItem(tag, i++, double_info);
                pPool->addItem(tag, i, double_info);
            }
                break;
            case constant_pool::JVM_CONSTANT_Fieldref: {
                byte *fieldinfo = (byte *) malloc(sizeof(byte) * 2);
                fieldinfo[0] = pReader->readU2Simple();
                fieldinfo[1] = pReader->readU2Simple();
                pPool->addItem(tag, i, fieldinfo);
            }
                break;
            case constant_pool::JVM_CONSTANT_NameAndType: {
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
    map<int, byte *> map = pPool->getDataMap();

    for (int i = 1; i <= map.size(); ++i) {
        printf("key = %d val = %s\n", i, map[i]);
    }


}

void class_loader::parseInterface(klass *pKlass, klass_reader *pReader) {
    int interfaceCount = pKlass->getInterfaceCount();
    if (interfaceCount<1)
    {
        return;
    }
    for (int i = 0; i < interfaceCount; ++i) {
        interface *interface = new class interface;
        interface->setNameIndex(pReader->readU2Simple());
        pKlass->getInterfaces()[i] = interface;
    }
}

void class_loader::parseField(klass *pKlass, klass_reader *pReader) {
    pKlass->setFieldInfos((field_info **) malloc(sizeof(field_info *) * pKlass->getFieldCount()));
    for (int i = 0; i < pKlass->getFieldCount(); ++i) {
        field_info *fieldInfo = new field_info;
        pKlass->getFieldInfos()[i] = fieldInfo;
        fieldInfo->setAccessFlags(pReader->readU2Simple());
        fieldInfo->setNameIndex(pReader->readU2Simple());
        fieldInfo->setDescriptorIndex(pReader->readU2Simple());
        fieldInfo->setAttributesCount(pReader->readU2Simple());
    }

}

void class_loader::parseMethod(klass *pKlass, klass_reader *pReader) {
    pKlass->setMethods((method **) malloc(sizeof(method **) * pKlass->getMethodCount()));
    for (int i = 0; i < pKlass->getMethodCount(); ++i) {
        method *method = new class method;
        pKlass->getMethods()[i] = method;
        method->setAccessFlags(pReader->readU2Simple());
        method->setNameIndex(pReader->readU2Simple());
        method->setDesIndex(pReader->readU2Simple());
        method->setAttrCount(pReader->readU2Simple());
        parseMethodAttr(method, pReader, pKlass);
    }
}

void class_loader::parseAttribute(klass *pKlass, klass_reader *pReader) {
    map<int,byte*> datamap = pKlass->getConstantPool()->getDataMap();

    int attr_index = pReader->readU2Simple();
    byte * name = datamap[attr_index];
    printf("name = %s", name);
}

code_attr ** class_loader::parseMethodAttr(method *pMethod, klass_reader *pReader, klass *klass) {
    int attrCount = pMethod->getAttrCount();
    if (attrCount<1)
    {
        return NULL;
    }
    code_attr **pCodeAttr = (code_attr **) malloc(sizeof(code_attr **) * attrCount);
    if (pCodeAttr == NULL) {
        return NULL;
    }
    code_attr *codeAttr = new code_attr;
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
//        line_number_table_attr *lineNumberTableAttr = new line_number_table_attr;
//        lineNumberTableAttr->setAttrLen(pReader->readU2Simple());
//        lineNumberTableAttr->setAttrLen(pReader->readU2Simple());
//        lineNumberTableAttr->setLineNumLen(pReader->readU2Simple());
//        for (int j = 0; j < lineNumberTableAttr->getLineNumLen(); ++j) {
//            line_number_table *lineNumberTable = new line_number_table;
//            lineNumberTable->setStartPc(pReader->readU2Simple());
//            lineNumberTable->setLineNumber(pReader->readU2Simple());
//        }
    }
    return pCodeAttr;
}

