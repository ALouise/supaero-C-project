#ifndef PERCOLATE_DFS_H
#define PERCOLATE_DFS_H

#include "grid.h"
#include <stdbool.h>

// Returns true if the grid percolates (using DFS)
bool percolates_dfs(grid *grid);

// Performs DFS from a given cell
void dfs(grid *grid, int row, int col);

#endif // PERCOLATE_DFS_H
