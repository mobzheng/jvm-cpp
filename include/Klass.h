
#ifndef JVM_CPP_KLASS_H
#define JVM_CPP_KLASS_H

#include "common.h"
#include "Interface.h"
#include "FieldInfo.h"
#include "Method.h"
#include "Attributes.h"
#include "ConstantPool.h"
#include <memory>
class ConstantPool;
class Klass {
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

    Attributes *getAttributes() const;

    void setAttributes(Attributes *attributes);

    ConstantPool *getConstantPool() const;

    void setConstantPool(ConstantPool *constantPool);

    Interface **getInterfaces() const;

    void setInterfaces(Interface **interfaces);

    FieldInfo **getFieldInfos() const;

    void setFieldInfos(FieldInfo **fieldInfos);

    Method **getMethods() const;

    void setMethods(Method **methods);

private:
    byte *magic;
    byte *minorVersion;
    byte *majorVersion;
    ConstantPool* constantPool;

    int accessFlags;
    int thisClass;
    int superClass;
    int interfaceCount;
    Interface** interfaces;
    int fieldCount;
    FieldInfo** fieldInfos;
    int methodCount;
    Method** methods;
    int attributesCount;
    Attributes* attributes;


};


#endif //JVM_CPP_KLASS_H
