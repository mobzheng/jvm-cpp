#include "include/ClassLoader.h"


int main() {
    ClassLoader *classLoader = new ClassLoader;
    classLoader->loadClass("/home/ff/CLionProjects/jvm-cpp/Test.class");

    return 0;
}
