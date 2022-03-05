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
    // Order for a tree is:
    // Enter : [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]
    /*                      8
     *          4                       12
     *     2       6                10       14
     * 1     3   5      7        9     11   13      15
    */
    // Out : [8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15]
}

int Btree_searchPointer(Btree_t *tree, void *target) {
    int low = 0;
    int high = tree->size - 1;
    int mid = 0;
    while(low <= high) {
        mid = (low + high) / 2;
        if(tree->compare(tree->data[mid], target) == 0) {
            return mid;
        } else if(tree->compare(tree->data[mid], target) < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int Btree_searchCopy(Btree_t tree, void *target) {
    int low = 0;
    int high = tree.size - 1;
    int mid = 0;
    while(low <= high) {
        mid = (low + high) / 2;
        if(tree.compare(tree.data[mid], target) == 0) {
            return mid;
        } else if(tree.compare(tree.data[mid], target) < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

void *Btree_get(Btree_t *tree, int index) {
    return tree->data[index];
}

Btree_t *Btree_add(Btree_t *tree, void *data) {
    tree->data = realloc(tree->data, (tree->size + 1) * sizeof(void *));
    tree->data[tree->size] = data;
    tree->size++;
    Btree_sort(tree);
    return tree;
}

void Btree_print(Btree_t *tree) {
    printf("Binary Tree size : %llu\n", tree->size);
    printf("Binary Tree data :  [ \n");
    for (unsigned long long i = 0; i < tree->size; i++) {
        tree->print(tree->data[i]);
    }
    printf("]\n");
}

int main() {
    printf("Hello, World! Btree.c\n");
    return 0;
}