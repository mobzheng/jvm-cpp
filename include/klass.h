
#ifndef JVM_CPP_KLASS_H
#define JVM_CPP_KLASS_H

#include "common.h"
#include "interface.h"
#include "field_info.h"
#include "method.h"
#include "attributes.h"
#include "constant_pool.h"
#include <memory>
class constant_pool;

class klass {
public:
    byte *getMagic() const;

    void setMagic(byte *magic);

    byte *getMinorVersion() const;

    void setMinorVersion(byte *minorVersion);

    byte *getMajorVersion() const;

    void setMajorVersion(byte *majorVersion);

    int getAccessFlags() const;

    void setAccessFlags(int accessFlags);

    int getThisClass() const;

    void setThisClass(int thisClass);

    int getSuperClass() const;

    void setSuperClass(int superClass);

    int getInterfaceCount() const;

    void setInterfaceCount(int interfaceCount);


    int getFieldCount() const;

    void setFieldCount(int fieldCount);


    int getMethodCount() const;

    void setMethodCount(int methodCount);


    int getAttributesCount() const;

    void setAttributesCount(int attributesCount);

    attributes *getAttributes() const;

    void setAttributes(class attributes *attributes);

    constant_pool *getConstantPool() const;

    void setConstantPool(constant_pool *constantPool);

    interface **getInterfaces() const;

    void setInterfaces(interface **interfaces);

    field_info **getFieldInfos() const;

    void setFieldInfos(field_info **fieldInfos);

    method **getMethods() const;

    void setMethods(method **methods);

private:
    byte *magic;
    byte *minorVersion;
    byte *majorVersion;
    constant_pool* constantPool;

    int accessFlags;
    int thisClass;
    int superClass;
    int interfaceCount;
    interface** interfaces;
    int fieldCount;
    field_info** fieldInfos;
    int methodCount;
    method** methods;
    int attributesCount;
    attributes* attributes;


};


#endif //JVM_CPP_KLASS_H
