#ifndef MEMORY_POOL_H
#define MEMORY_POOL_H

#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T, size_t PoolSize = 10>
class MemoryPool {
    void* pool[PoolSize];
    bool used[PoolSize];

public:
    MemoryPool() {
        for (size_t i = 0; i < PoolSize; ++i) {
            pool[i] = malloc(sizeof(T));
            used[i] = false;
        }
    }

    ~MemoryPool() {
        for (size_t i = 0; i < PoolSize; ++i) {
            free(pool[i]);
        }
    }

    void* allocate() {
        for (size_t i = 0; i < PoolSize; ++i) {
            if (!used[i]) {
                used[i] = true;
                cout << "[Pool] Allocating slot " << i << "\n";
                return pool[i];
            }
        }
        cout << "[Pool] Pool exhausted, using fallback malloc\n";
        return malloc(sizeof(T));
    }

    void deallocate(void* ptr) {
        for (size_t i = 0; i < PoolSize; ++i) {
            if (pool[i] == ptr) {
                used[i] = false;
                cout << "[Pool] Releasing slot " << i << "\n";
                return;
            }
        }
        cout << "[Pool] Fallback free\n";
        free(ptr);
    }
};

#endif
