#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "grid.h"
#include "percolate_dfs.h"
#include "simulation_dfs.h"

int monte_carlo_simulation(int width, int height, int sim_number) {

    grid *grid = create_grid(width, height);
    if (!grid) {
        fprintf(stderr, "Error: Failed to create grid.\n");
        return -1;
    }

    int open_count = 0;

    while (!percolates_dfs(grid)) {
        int col = rand() % width;
        int row = rand() % height;

        cell *cell = get_cell(grid, row, col);
        if (!cell->is_open) {
            set_cell(grid, row, col, true);
            open_count++;
        }
    }

    char filename[100];
    snprintf(filename, sizeof(filename), "out/test-mc-dfs-%d.ppm", sim_number);
    generate_image(grid, filename);

    free_grid(grid);

    return open_count;
}
