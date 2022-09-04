#include "../include/BtreeInt.hpp"

Btree_Int_t Btree_Int_Constructor(int *data, size_t size) {
    Btree_Int_t t = new Btree_Int_s;
    t->data = new int[size];
    t->size = size;
    for (size_t i = 0; i < t->size; i++) {
        t->data[i] = data[i];
    }
    return t;
}