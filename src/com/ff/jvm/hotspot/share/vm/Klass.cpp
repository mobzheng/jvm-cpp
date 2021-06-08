//
// Created by zhengzhipeng on 2021/6/7.
//

#include "../../../../../../../include/Klass.h"


byte *Klass::getMagic() const {
    return magic;
}

void Klass::setMagic(byte *magic) {
    Klass::magic = magic;
}

byte *Klass::getMinorVersion() const {
    return minorVersion;
}

void Klass::setMinorVersion(byte *minorVersion) {
    Klass::minorVersion = minorVersion;
}

byte *Klass::getMajorVersion() const {
    return majorVersion;
}

void Klass::setMajorVersion(byte *majorVersion) {
    Klass::majorVersion = majorVersion;
}

int Klass::getAccessFlags() const {
    return accessFlags;
}

void Klass::setAccessFlags(int accessFlags) {
    Klass::accessFlags = accessFlags;
}

int Klass::getThisClass() const {
    return thisClass;
}

void Klass::setThisClass(int thisClass) {
    Klass::thisClass = thisClass;
}

int Klass::getSuperClass() const {
    return superClass;
}

void Klass::setSuperClass(int superClass) {
    Klass::superClass = superClass;
}

int Klass::getInterfaceCount() const {
    return interfaceCount;
}

void Klass::setInterfaceCount(int interfaceCount) {
    Klass::interfaceCount = interfaceCount;
}


int Klass::getFieldCount() const {
    return fieldCount;
}

void Klass::setFieldCount(int fieldCount) {
    Klass::fieldCount = fieldCount;
}


int Klass::getMethodCount() const {
    return methodCount;
}

void Klass::setMethodCount(int methodCount) {
    Klass::methodCount = methodCount;
}


int Klass::getAttributesCount() const {
    return attributesCount;
}

void Klass::setAttributesCount(int attributesCount) {
    Klass::attributesCount = attributesCount;
}

Attributes *Klass::getAttributes() const {
    return attributes;
}

void Klass::setAttributes(Attributes *attributes) {
    Klass::attributes = attributes;
}

ConstantPool *Klass::getConstantPool() const {
    return constantPool;
}

void Klass::setConstantPool(ConstantPool *constantPool) {
    Klass::constantPool = constantPool;
}

Interface **Klass::getInterfaces() const {
    return interfaces;
}

void Klass::setInterfaces(Interface **interfaces) {
    Klass::interfaces = interfaces;
}

FieldInfo **Klass::getFieldInfos() const {
    return fieldInfos;
}

void Klass::setFieldInfos(FieldInfo **fieldInfos) {
    Klass::fieldInfos = fieldInfos;
}

Method **Klass::getMethods() const {
    return methods;
}

void Klass::setMethods(Method **methods) {
    Klass::methods = methods;
}




