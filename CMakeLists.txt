cmake_minimum_required(VERSION 3.19)
project(jvm_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(jvm_cpp main.cpp src/com/ff/jvm/hotspot/share/vm/Klass.cpp include/Klass.h src/com/ff/jvm/hotspot/share/vm/ClassLoader.cpp include/ClassLoader.h include/common.h src/com/ff/jvm/hotspot/share/vm/Reader.cpp include/Reader.h)