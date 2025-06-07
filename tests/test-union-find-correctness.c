#include "union_find.h"
#include <stdio.h>

int main() {
    union_find *uf = create_uf(10);

    merge(uf, 1, 2);
    merge(uf, 2, 3);
    merge(uf, 4, 5);

    printf("Find(1): %d\n", find(uf, 1));
    printf("Find(2): %d\n", find(uf, 2));
    printf("Find(3): %d\n", find(uf, 3));
    printf("Find(4): %d\n", find(uf, 4));
    printf("Find(5): %d\n", find(uf, 5));

    if (find(uf, 1) == find(uf, 3)) {
        printf("1 and 3 are connected.\n");
    }
    if (find(uf, 4) != find(uf, 3)) {
        printf("4 and 3 are NOT connected.\n");
    }

    free_uf(uf);
    return 0;
}
