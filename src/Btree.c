#include "../include/Btree.h"

Btree_t *Btree_create(void **data, unsigned long long size, int (*compare)(const void *, const void *), void (*destroy)(void *), void (*print)(void *)) {
    Btree_t *tree = malloc(sizeof(Btree_t));
    tree->data = data;
    tree->size = size;
    tree->compare = compare;
    tree->destroy = destroy;
    tree->print = print;
    Btree_sort(tree);
    return tree;
}

void Btree_destroy(Btree_t *tree) {
    for(unsigned long long i = 0; i < tree->size; i++) {
        tree->destroy(tree->data[i]);
    }
    free(tree->data);
    free(tree);
}

void Btree_sort(Btree_t *tree) {
    qsort(tree->data, tree->size, sizeof(void *), tree->compare);
}

Btree_t *Btree_add(Btree_t *tree, void *data) {
    tree->data = realloc(tree->data, (tree->size + 1) * sizeof(void *));
    tree->data[tree->size] = data;
    tree->size++;
    Btree_sort(tree);
    return tree;
}

void Btree_print(Btree_t *tree) {
    for (unsigned long long i = 0; i < tree->size; i++) {
        tree->print(tree->data[i]);
    }
}

int main() {
    printf("Hello, World! Btree.c\n");
    return 0;
}