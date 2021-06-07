
#ifndef JVM_CPP_KLASS_H
#define JVM_CPP_KLASS_H

#include "common.h"

class Klass {
public:
    byte *getMagic() const;

    void setMagic(byte *magic);

    byte *getMinorVersion() const;

    void setMinorVersion(byte *minorVersion);

    byte *getMajorVersion() const;

    void setMajorVersion(byte *majorVersion);

private:
    byte *magic;
    byte *minorVersion;
    byte *majorVersion;

};


#endif //JVM_CPP_KLASS_H
