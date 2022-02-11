#pragma once

#include <iostream>
#include <algorithm>
#include <cmath>

template<typename T>
class Btree {
private:
    size_t m_Size;
    size_t m_Deep;
    T* m_Tree;

public:
    Btree(void) {
        this->m_Size = 0;
        this->m_Deep = 0;
        this->m_Tree = nullptr;
    }

    Btree(size_t size) {
        this->m_Size = size;
        this->m_Tree = new T[this->m_Size];
        this->m_Deep = std::log2(this->m_Size + 1);
        std::cout << "Btree created with size: " << this->m_Deep << std::endl;
    }

    ~Btree() {
    }

    void setTree(T* tree, size_t size) {
        this->m_Tree = tree;
        this->m_Size = size;
        this->m_Deep = std::log2(this->m_Size + 1);
        std::cout << "Btree created with size: " << this->m_Deep << std::endl;
    }

    bool exists(T value) {
        size_t i = 0;
        size_t p = 0;
        while (i < this->m_Size) {
            if (value == this->m_Tree[p]) {
                return true;
            } else if (value < this->m_Tree[p]) {
                p += 1 + i;
            } else if (value > this->m_Tree[p]) {
                p += 2 + i;
            } else {
                return false;
            }
            i ++;
        }
        return false;
    }

    void print() {
        int posi = 0;
        int printing = 1;
        for (size_t i = 0; i < this->m_Deep; i ++) {
            for (int j = 0; j < printing ; j ++) {
                for (int k = 0; k < this->m_Deep - i + 1; k ++) {
                    std::cout << "\t";
                }
                std::cout << this->m_Tree[posi];
                posi ++;
            }
            printing *= 2;
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void sortGrowing(void) {
        std::sort(this->m_Tree, this->m_Tree + this->m_Size);
    }

    bool isSort(void) {
        for (size_t i = 0; i < this->m_Deep - 1; i ++) {

        }
        return true;
    }

    void sort(void) {
        this->sortGrowing();
    }
};