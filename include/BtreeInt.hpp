#pragma once

#include <iostream>

typedef struct Btree_Int_s {
    int *data;
    size_t size;
} *Btree_Int_t;

Btree_Int_t Btree_Int_Constructor(int *data, size_t size);