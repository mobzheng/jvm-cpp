//
// Created by zhengzhipeng on 2021/6/10.
//

#ifndef JVM_CPP_MEMORY_CELL_H
#define JVM_CPP_MEMORY_CELL_H

// 每个cell8个字节

class memory_cell {
private:
    int start;
    // 大小
    int size;
    // 剩余
    int free;
public:
    int getStart() const;

    void setStart(int start);

    int getSize() const;

    void setSize(int size);

    int getFree() const;

    void setFree(int free);

};


#endif //JVM_CPP_MEMORY_CELL_H
