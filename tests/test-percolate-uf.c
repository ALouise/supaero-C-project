#include "grid.h"
#include "loader.h"
#include <stdio.h>

int main() {
    // Load a grid from file
    const char *filename = "data/grid_np_1.txt";
    grid *grid = load_grid(filename);
    if (!grid) {
        return 1;
    }

    // Print the grid
    printf("Grid:\n");
    print_grid(grid);

    // Check percolation
    if (percolates_uf(grid)) {
        printf("The system percolates! \n");
    } else {
        printf("The system does NOT percolate.\n");
    }

    free_grid(grid);
    return 0;
}
