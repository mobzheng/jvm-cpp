#include "include/ClassLoader.h"
#include <map>
#include <string>
using namespace std;
int main() {
    ClassLoader *classLoader = new ClassLoader;
    classLoader->loadClass("/Users/zhengzhipeng/Documents/code/jvm-cpp/Test.class");
    return 0;
}
