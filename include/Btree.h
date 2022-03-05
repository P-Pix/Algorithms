#ifndef __BTREE_H__
#define __BTREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Btree_s {
    void **data;
    unsigned long long size;
    int (*compare)(const void *, const void *);
    void (*destroy)(void *);
    void (*print)(void *);
} Btree_t;

Btree_t *Btree_create(void **data, unsigned long long size, int (*compare)(const void *, const void *), void (*destroy)(void *), void (*print)(void *));
void Btree_destroy(Btree_t *tree);
void Btree_print(Btree_t *tree);
void Btree_sort(Btree_t *tree);
Btree_t *Btree_add(Btree_t *tree, void *data);
void *Btree_get(Btree_t *tree, int index);

// Need test to know who is faster
int Btree_searchPointer(Btree_t *tree, void *target);
int Btree_searchCopy(Btree_t tree, void *target);

#endif