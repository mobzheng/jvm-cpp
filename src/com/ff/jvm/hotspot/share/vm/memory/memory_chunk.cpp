//
// Created by zhengzhipeng on 2021/6/10.
//

#include "../../../../../../../../include/memory_chunk.h"

const list<memory_cell *> &memory_chunk::getAvailableCell() const {
    return available_cell;
}

void memory_chunk::setAvailableCell(const list<memory_cell *> &availableCell) {
    available_cell = availableCell;
}

const list<memory_cell *> &memory_chunk::getUsedCell() const {
    return used_cell;
}

void memory_chunk::setUsedCell(const list<memory_cell *> &usedCell) {
    used_cell = usedCell;
}

int memory_chunk::getMAlignSize() const {
    return m_align_size;
}

void memory_chunk::setMAlignSize(int mAlignSize) {
    m_align_size = mAlignSize;
}

int memory_chunk::getMCellSize() const {
    return m_cell_size;
}

void memory_chunk::setMCellSize(int mCellSize) {
    m_cell_size = mCellSize;
}

int memory_chunk::getChunkSize() const {
    return chunk_size;
}

void memory_chunk::setChunkSize(int chunkSize) {
    chunk_size = chunkSize;
}

int memory_chunk::getUsedSize() const {
    return used_size;
}

void memory_chunk::setUsedSize(int usedSize) {
    used_size = usedSize;
}

memory_chunk::memory_chunk(int size):chunk_size(size) {


}
