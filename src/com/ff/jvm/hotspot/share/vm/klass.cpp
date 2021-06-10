//
// Created by zhengzhipeng on 2021/6/7.
//

#include "../../../../../../../include/klass.h"


byte *klass::getMagic() const {
    return magic;
}

void klass::setMagic(byte *magic) {
    klass::magic = magic;
}

byte *klass::getMinorVersion() const {
    return minorVersion;
}

void klass::setMinorVersion(byte *minorVersion) {
    klass::minorVersion = minorVersion;
}

byte *klass::getMajorVersion() const {
    return majorVersion;
}

void klass::setMajorVersion(byte *majorVersion) {
    klass::majorVersion = majorVersion;
}

int klass::getAccessFlags() const {
    return accessFlags;
}

void klass::setAccessFlags(int accessFlags) {
    klass::accessFlags = accessFlags;
}

int klass::getThisClass() const {
    return thisClass;
}

void klass::setThisClass(int thisClass) {
    klass::thisClass = thisClass;
}

int klass::getSuperClass() const {
    return superClass;
}

void klass::setSuperClass(int superClass) {
    klass::superClass = superClass;
}

int klass::getInterfaceCount() const {
    return interfaceCount;
}

void klass::setInterfaceCount(int interfaceCount) {
    klass::interfaceCount = interfaceCount;
}


int klass::getFieldCount() const {
    return fieldCount;
}

void klass::setFieldCount(int fieldCount) {
    klass::fieldCount = fieldCount;
}


int klass::getMethodCount() const {
    return methodCount;
}

void klass::setMethodCount(int methodCount) {
    klass::methodCount = methodCount;
}


int klass::getAttributesCount() const {
    return attributesCount;
}

void klass::setAttributesCount(int attributesCount) {
    klass::attributesCount = attributesCount;
}

attributes *klass::getAttributes() const {
    return attributes;
}

void klass::setAttributes(class attributes *attributes) {
    klass::attributes = attributes;
}

constant_pool *klass::getConstantPool() const {
    return constantPool;
}

void klass::setConstantPool(constant_pool *constantPool) {
    klass::constantPool = constantPool;
}

interface **klass::getInterfaces() const {
    return interfaces;
}

void klass::setInterfaces(interface **interfaces) {
    klass::interfaces = interfaces;
}

field_info **klass::getFieldInfos() const {
    return fieldInfos;
}

void klass::setFieldInfos(field_info **fieldInfos) {
    klass::fieldInfos = fieldInfos;
}

method **klass::getMethods() const {
    return methods;
}

void klass::setMethods(method **methods) {
    klass::methods = methods;
}




