#include "grid.h"

int main() {
    // Create a 5x5 grid
    grid *grid = create_grid(5, 5);
    if (!grid) {
        return 1;
    }

    // Open a few selected cells
    set_cell(grid, 1, 1, true);
    set_cell(grid, 2, 2, true);
    set_cell(grid, 3, 3, true);

    // Print the grid to visualize changes
    print_grid(grid);

    // Free allocated memory
    free_grid(grid);

    return 0;
}
