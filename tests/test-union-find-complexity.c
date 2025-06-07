#include "union_find.h"
#include <stdio.h>
#include <time.h>

int main() {
    int n = 1000000; // 1 million elements
    union_find *uf = create_uf(n);

    clock_t start = clock();
    
    // Perform union operations
    for (int i = 1; i < n; i++) {
        merge(uf, i - 1, i);
    }

    // Perform find operations
    for (int i = 0; i < n; i++) {
        find(uf, i);
    }

    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken for 1M operations: %.4f seconds\n", time_taken);

    free_uf(uf);
    return 0;
}
