#include "percolate_dfs.h"
#include "grid.h"

void dfs(grid *grid, int row, int col) {
    // Check out of bounds
    if (row < 0 || row >= grid->height || col < 0 || col >= grid->width) return;

    // Get the cell
    cell *cell = get_cell(grid, row, col);

    // Check if already visited or blocked
    if (cell == NULL || cell->is_visited || !cell->is_open) return;

    // Mark the cell as visited
    cell->is_visited = true;

    // Recursively explore neighbors (c1, c2, c3, c4)
    dfs(grid, row - 1, col); // Up
    dfs(grid, row, col - 1); // Left
    dfs(grid, row, col + 1); // Right
    dfs(grid, row + 1, col); // Down
}

bool percolates_dfs(grid *grid) {
    // Reset the visited flags
    for (int i = 0; i < grid->width * grid->height; i++) {
        grid->cells[i].is_visited = false;
    }

    // Start DFS from top row
    for (int col = 0; col < grid->width; col++) {
        cell *start_cell = get_cell(grid, 0, col);
        if (start_cell->is_open) {
            dfs(grid, 0, col);
        }
    }

    // Check if any cell in the bottom row is visited
    for (int col = 0; col < grid->width; col++) {
        if (get_cell(grid, grid->height - 1, col)->is_visited) {
            return true;
        }
    }

    return false;
}
