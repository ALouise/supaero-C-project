#include "union_find.h"
#include <stdio.h>

// Creates a Union-Find structure with 'n' elements
union_find *create_uf(int n) {
    union_find *uf = malloc(sizeof(union_find));
    if (!uf) return NULL;

    uf->size = n;
    uf->parent = malloc(n * sizeof(int));
    uf->rank = malloc(n * sizeof(int));

    if (!uf->parent || !uf->rank) {
        free(uf->parent);
        free(uf->rank);
        free(uf);
        return NULL;
    }

    // Initialize sets (each element is its own parent)
    for (int i = 0; i < n; i++) {
        uf->parent[i] = i;
        uf->rank[i] = 0;
    }

    return uf;
}

int find(union_find *uf, int e) {
    if (uf->parent[e] != e) {
        uf->parent[e] = find(uf, uf->parent[e]); 
    }
    return uf->parent[e];
}

void merge(union_find *uf, int e1, int e2) {
    int root1 = find(uf, e1);
    int root2 = find(uf, e2);

    if (root1 != root2) {
        if (uf->rank[root1] > uf->rank[root2]) {
            uf->parent[root2] = root1;
        } else if (uf->rank[root1] < uf->rank[root2]) {
            uf->parent[root1] = root2;
        } else {
            uf->parent[root2] = root1;
            uf->rank[root1]++;
        }
    }
}

// Frees the Union-Find structure
void free_uf(union_find *uf) {
    free(uf->parent);
    free(uf->rank);
    free(uf);
}
