#include "include/ClassLoader.h"

int main() {
    ClassLoader *classLoader = new ClassLoader;
    classLoader->loadClass("/Users/zhengzhipeng/Documents/code/jvm-cpp/Test.class");

    return 0;
}
