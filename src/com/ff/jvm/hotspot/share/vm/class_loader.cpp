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
    constant_pool *constantPool = new constant_pool(klass, reader->readU2Simple());
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
            case constant_pool::JVM_CONSTANT_Class: {
                tags[i] = tag;
                int class_val = pReader->readU2Simple();
                pPool->addItem(tag, i, &class_val);
                PRINT("#%d = %s\t#%d\n", i, "JVM_CONSTANT_Class", class_val);
            }
                break;
            case constant_pool::JVM_CONSTANT_Utf8: {
                tags[i] = tag;
                int str_len = pReader->readU2Simple();
                byte *str = pReader->read(str_len);
                pPool->addItem(tag, i, str);
                PRINT("#%d = %s\t%s\n", i, "JVM_CONSTANT_Utf8", str);
            }
                break;
            case constant_pool::JVM_CONSTANT_String: {

                int str_index = pReader->readU2Simple();
                pPool->addItem(tag, i, &str_index);
                PRINT("#%d = %s\t#%d\n", i, "JVM_CONSTANT_Class", str_index);

            }
                break;
            case constant_pool::JVM_CONSTANT_Methodref: {
                byte *method = (byte *) malloc(sizeof(byte) * 2);
                method[0] = pReader->readU2Simple();
                method[1] = pReader->readU2Simple();
                pPool->addItem(tag, i, method);
                PRINT("#%d = %s\t#%hhu.#%hhu \n", i, "JVM_CONSTANT_Utf8", method[0], method[1]);
            }
                break;
            case constant_pool::JVM_CONSTANT_Double: {
                tags[i] = tag;
                double double_val = atof(pReader->readU8());
                PRINT("#%d = %s\t%fl \n", i, "JVM_CONSTANT_Double", double_val);
                pPool->addItem(tag, i++, &double_val);
                pPool->addItem(tag, i, &double_val);
                PRINT("#%d = %s\t%fl \n", i, "JVM_CONSTANT_Double", double_val);
            }
                break;
            case constant_pool::JVM_CONSTANT_Fieldref: {
                byte *fieldinfo = (byte *) malloc(sizeof(byte) * 2);
                fieldinfo[0] = pReader->readU2Simple();
                fieldinfo[1] = pReader->readU2Simple();
                pPool->addItem(tag, i, fieldinfo);
                PRINT("#%d = %s\t#%hhu.#%hhu \n", i, "JVM_CONSTANT_Fieldref", fieldinfo[0], fieldinfo[1]);
            }
                break;
            case constant_pool::JVM_CONSTANT_NameAndType: {
                byte *name_type = (byte *) malloc(sizeof(byte));
                name_type[0] = pReader->readU2Simple();
                name_type[1] = pReader->readU2Simple();
                pPool->addItem(tag, i, name_type);
                PRINT("#%d = %s\t#%hhu.#%hhu \n", i, "JVM_CONSTANT_NameAndType", name_type[0], name_type[1]);

            }
                break;
            default:
                ERROR_PRINT("未支持的类型 tag = %d index = %d  上一个 tag = %d", tag, i, tags[i - 1]);
                exit(0);
        }

    }
    PRINT("常量池解析完毕\n");
}

void class_loader::parseInterface(klass *pKlass, klass_reader *pReader) {
    int interfaceCount = pKlass->getInterfaceCount();
    if (interfaceCount < 1) {
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
        for (int j = 0; j < fieldInfo->getAttributesCount(); ++j) {
            parseAttribute(pKlass, pReader);
        }
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

code_attr *class_loader::parseAttribute(klass *pKlass, klass_reader *pReader) {
    map<int, void *> datamap = pKlass->getConstantPool()->getDataMap();
    int attr_index = pReader->readU2Simple();
    byte *name = (byte *) datamap[attr_index];
    if (!strcmp("ConstantValue", name)) {
        int attr_len = pReader->readU4Simple();
        int constant_val = pReader->readU2Simple();
    }

    PRINT("name = %s", name);
}

code_attr **class_loader::parseMethodAttr(method *pMethod, klass_reader *pReader, klass *_klass) {
    map<int, void *> data_map = _klass->getConstantPool()->getDataMap();
    int attrCount = pMethod->getAttrCount();
    if (attrCount < 1) {
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

        for (int j = 0; j < codeAttr->getAttrCount(); ++j) {
            int code_name_index = pReader->readU2Simple();
            j += 2;

            byte *attr_name = (byte *) data_map.find(code_name_index)->second;
            if (strstr(attr_name, "LineNumberTable")) {
                line_number_table_attr *lineNumberTableAttr = new line_number_table_attr;

                lineNumberTableAttr->setAttrNameIndex(code_name_index);
                lineNumberTableAttr->setAttrLen(pReader->readU4Simple());
                j  += 4;

                lineNumberTableAttr->setLineNumLen(pReader->readU2Simple());
                j += 2;

                for (int k = 0; k < lineNumberTableAttr->getLineNumLen(); ++k) {
                    line_number_table *lineNumberTable = new line_number_table;
//                    lineNumberTableAttr->getLineNumberTable()[k] = lineNumberTable;
                    lineNumberTable->setStartPc(pReader->readU2Simple());
                    j += 2;
                    lineNumberTable->setLineNumber(pReader->readU2Simple());
                    j += 2;
                }
            } else if (strstr(attr_name, "LocalVariableTable")) {
                local_variable_table_attribute *localVariableTableAttribute = new local_variable_table_attribute;
                localVariableTableAttribute->setAttrNameIndex(code_name_index);
                localVariableTableAttribute->setAttrLen(pReader->readU4Simple());
                j+= 4;
                localVariableTableAttribute->setLocalVariableLen(pReader->readU2Simple());
                j+= 2;
                for (int k = 0; k < localVariableTableAttribute->getLocalVariableLen(); ++k) {
                    local_variable_table *localVariableTable = new local_variable_table;
//                    localVariableTableAttribute->getPVariableTable()[k] = localVariableTable;
                    localVariableTable->setStartPc(pReader->readU2Simple());
                    j+= 2;
                    localVariableTable->setLen(pReader->readU2Simple());
                    j+= 2;
                    localVariableTable->setNameIndex(pReader->readU2Simple());
                    j+= 2;
                    localVariableTable->setDescriptorIndex(pReader->readU2Simple());
                    j+= 2;
                    localVariableTable->setIndex(pReader->readU2Simple());
                    j+= 2;
                }
            }
            PRINT("解析  %s", attr_name);
        }


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

