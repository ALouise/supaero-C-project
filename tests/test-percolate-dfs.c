#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "grid.h"
#include "loader.h"
#include "percolate_dfs.h"


void run_test(const char *filename, bool expected) {
    grid *grid = load_grid(filename);
    assert(grid != NULL);

    bool result = percolates_dfs(grid);
    printf("Testing %s: %s\n", filename, result ? "Percolates" : "Does NOT percolate");

    // Check if result matches expectation
    assert(result == expected);

    // Generate the output image
    char image_filename[100];
    snprintf(image_filename, sizeof(image_filename), "out/%s-dfs.ppm", filename + 5); // Remove "data/"
    generate_image(grid, image_filename);

    // Free memory
    free_grid(grid);
}

int main() {
    printf("Running percolation tests...\n");

    // Non-percolating grids
    run_test("data/grid_np_1.txt", false);
    run_test("data/grid_np_2.txt", false);
    run_test("data/grid_np_3.txt", false);
    run_test("data/grid_np_4.txt", false);
    run_test("data/grid_np_5.txt", false);

    // Percolating grids
    run_test("data/grid_p_1.txt", true);
    run_test("data/grid_p_2.txt", true);
    run_test("data/grid_p_3.txt", true);
    run_test("data/grid_p_4.txt", true);
    run_test("data/grid_p_5.txt", true);
    run_test("data/grid_p_6.txt", true);
    run_test("data/grid_p_7.txt", true);
    run_test("data/grid_p_8.txt", true);
    run_test("data/grid_p_9.txt", true);
    run_test("data/grid_p_10.txt", true);

    printf("All tests passed!\n");
    return 0;
}
