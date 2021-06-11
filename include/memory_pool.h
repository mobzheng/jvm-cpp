//
// Created by zhengzhipeng on 2021/6/10.
//

#ifndef JVM_CPP_MEMORY_POOL_H
#define JVM_CPP_MEMORY_POOL_H
#include <list>
#include "common.h"
#include "memory_chunk.h"
using namespace std;


class memory_pool {
private:
    list<memory_chunk*> memory_chunks;
public:
    memory_chunk *malloc_memory_chunk(int size);

    void free_memory_chunks();
};


#endif //JVM_CPP_MEMORY_POOL_H
