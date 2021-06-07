
#ifndef JVM_CPP_CLASSLOADER_H
#define JVM_CPP_CLASSLOADER_H
#include <string>
#include "Reader.h"
#include "Klass.h"
class ClassLoader {
public:
    void loadClass(char *className);

    Klass *parseKlass(Reader*  reader);

};


#endif //JVM_CPP_CLASSLOADER_H
