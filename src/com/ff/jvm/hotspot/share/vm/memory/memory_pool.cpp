//
// Created by zhengzhipeng on 2021/6/10.
//

#include "../../../../../../../../include/memory_pool.h"

memory_chunk *memory_pool::malloc_memory_chunk(int size) {
    memory_chunk *chunk = new memory_chunk(size);
    memory_pool::memory_chunks.push_front(chunk);
    return chunk;
}

void memory_pool::free_memory_chunks() {

    list<memory_chunk*>::iterator iterator;

    for (iterator = memory_chunks.begin(); iterator != memory_chunks.end(); iterator++) {
        delete (*iterator);
    }
    memory_chunks.clear();
    PRINT("释放内存池");

}
