#include "loader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to load a grid from a text file
grid *load_grid(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
        return NULL;
    }

    int width, height;
    char line[1024];

    // Read first line to get dimensions
    if (!fgets(line, sizeof(line), file)) {
        fprintf(stderr, "Error: Cannot read first line from %s\n", filename);
        fclose(file);
        return NULL;
    }

    if (sscanf(line, "%d %d", &width, &height) != 2) {
        fprintf(stderr, "Error: Invalid format in first line of %s\n", filename);
        fclose(file);
        return NULL;
    }

    printf("Loading grid from %s\n", filename);
    printf("Grid size: width=%d, height=%d\n", width, height);

    // Create the grid
    grid *grid = create_grid(width, height);
    if (!grid) {
        fprintf(stderr, "Error: Memory allocation failed for grid\n");
        fclose(file);
        return NULL;
    }

    // Read the grid from file
    for (int row = 0; row < height; row++) {
        if (!fgets(line, sizeof(line), file)) {
            fprintf(stderr, "Error: Unexpected EOF in %s at row %d\n", filename, row);
            free_grid(grid);
            fclose(file);
            return NULL;
        }

        printf("Row %d: %s", row, line); // Debugging print

        for (int col = 0; col < width; col++) {
            if (line[col] == '#') {
                set_cell(grid, row, col, false);  // Blocked cell
            } else {
                set_cell(grid, row, col, true);   // Open cell
            }
        }
    }

    fclose(file);
    return grid;
}
