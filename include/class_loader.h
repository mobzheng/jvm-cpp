
#ifndef JVM_CPP_CLASS_LOADER_H
#define JVM_CPP_CLASS_LOADER_H
#include <string>
#include "klass_reader.h"
#include "klass.h"
#include "constant_pool.h"
#include "code_attr.h"
#include "line_number_table.h"
#include "line_number_table_attr.h"
#include "local_variable_table_attribute.h"
#include "local_variable_table.h"
class class_loader {
public:
    void loadClass(char *className);

    klass *parseKlass(klass_reader*  reader);

    void parseConstantPool(constant_pool *pPool, klass_reader *pReader);

    void parseInterface(klass *pKlass, klass_reader *pReader);

    void parseField(klass *pKlass, klass_reader *pReader);

    void parseMethod(klass *pKlass, klass_reader *pReader);

     code_attr* parseAttribute(klass *pKlass, klass_reader *pReader);

    code_attr ** parseMethodAttr(method *pMethod, klass_reader *pReader, klass *klass);

};


#endif //JVM_CPP_CLASS_LOADER_H
