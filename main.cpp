#include "include/class_loader.h"
#include <map>
#include <string>
using namespace std;
int main() {
    class_loader *classLoader = new class_loader;
    classLoader->loadClass("/Users/zhengzhipeng/Documents/code/jvm-cpp/Test.class");

    return 0;
}
