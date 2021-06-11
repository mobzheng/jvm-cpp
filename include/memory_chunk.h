//
// Created by zhengzhipeng on 2021/6/10.
//

#ifndef JVM_CPP_MEMORY_CHUNK_H
#define JVM_CPP_MEMORY_CHUNK_H

#include "memory_cell.h"
#include <list>
using namespace std;
class memory_chunk {

    list<memory_cell*> available_cell ;
    list<memory_cell*> used_cell ;

    // 对齐方式
    int m_align_size;

    // 该chunk包含的cell数量
    int m_cell_size;

    // chunk总的内存
    int chunk_size;

    // 已经使用的内存量
    int used_size;

    // 数据存储区
    void * data;

public:
    memory_chunk(int size);
    const list<memory_cell *> &getAvailableCell() const;

    void setAvailableCell(const list<memory_cell *> &availableCell);

    const list<memory_cell *> &getUsedCell() const;

    void setUsedCell(const list<memory_cell *> &usedCell);

    int getMAlignSize() const;

    void setMAlignSize(int mAlignSize);

    int getMCellSize() const;

    void setMCellSize(int mCellSize);

    int getChunkSize() const;

    void setChunkSize(int chunkSize);

    int getUsedSize() const;

    void setUsedSize(int usedSize);
};


#endif //JVM_CPP_MEMORY_CHUNK_H
