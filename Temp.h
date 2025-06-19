// temp.h
#ifndef TEMP_H
#define TEMP_H

#include <iostream>
#include <fstream>
#include "MemoryPool.h"
using namespace std;

class temp {
    string id, name, author, search;
    fstream file;

    static MemoryPool<temp> pool;

public:
    void addBook();
    void showAll();
    void extractBook();

    // Pool-enabled new/delete
    void* operator new(size_t size) {
        return pool.allocate();
    }

    void operator delete(void* ptr) {
        pool.deallocate(ptr);
    }
};

#endif
