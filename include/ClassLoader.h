
#ifndef JVM_CPP_CLASSLOADER_H
#define JVM_CPP_CLASSLOADER_H
#include <string>
#include "Reader.h"
#include "Klass.h"
#include "ConstantPool.h"

class ClassLoader {
public:
    void loadClass(char *className);

    Klass *parseKlass(Reader*  reader);

    void parseConstantPool(ConstantPool *pPool, Reader *pReader);

    void parseInterface(Klass *pKlass, Reader *pReader);

    void parseField(Klass *pKlass, Reader *pReader);

    void parseMethod(Klass *pKlass, Reader *pReader);

     void parseAttribute(Klass *pKlass, Reader *pReader);

    CodeAttr ** parseMethodAttr(Method *pMethod, Reader *pReader, Klass *klass);

};


#endif //JVM_CPP_CLASSLOADER_H
