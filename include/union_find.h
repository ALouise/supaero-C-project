#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <stdlib.h>

// Union-Find structure
typedef struct {
    int *parent;
    int *rank;
    int size;
} union_find;

// Creates a Union-Find structure with n elements
union_find *create_uf(int n);

// Frees the memory of a Union-Find structure
void free_uf(union_find *uf);

// Finds the root of element e (with path compression)
int find(union_find *uf, int e);

// Merges the sets containing e1 and e2
void merge(union_find *uf, int e1, int e2);

#endif // UNION_FIND_H
