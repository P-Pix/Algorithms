#pragma once

#include <iostream>

template <typename T>
class List {
private:
    T *m_Data;
    size_t m_Size;
public:
    List(void) {
        this->m_Data = nullptr;
        this->m_Size = 0;
    }

    List(size_t size) {
        this->m_Data = new T[size];
        this->m_Size = size;
    }

    List(List<T> *list) {
        this->m_Data = new T[list->getSize()];
        this->m_Size = list->getSize();
        for (size_t i = 0; i < this->m_Size; i++) {
            this->m_Data[i] = list->getData(i);
        }
    }

    ~List(void) {
    }

    void setSize(size_t size) {
        this->m_Size = size;
        this->extend(size - this->m_Size);
    }

    void extend(size_t size) {
        T *temp = new T[this->m_Size + size];
        for (size_t i = 0; i < this->m_Size; i++) {
            temp[i] = this->m_Data[i];
        }
        delete[] this->m_Data;
        this->m_Data = temp;
        this->m_Size += size;
    }

    size_t getSize(void) {
        return this->m_Size;
    }

    T get(size_t index) {
        return this->m_Data[index];
    }

    void insert(size_t index, T value) {
        this->extend(1);
        for (size_t i = this->m_Size - 1; i > index; i--) {
            this->m_Data[i] = this->m_Data[i - 1];
        }
        this->m_Data[index] = value;
    }
};