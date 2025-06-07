#include "grid.h"

// Creates a new grid and initializes all cells as blocked
#include "grid.h"

grid *create_grid(int width, int height) {
    grid *g = malloc(sizeof(grid));
    if (g == NULL) return NULL;

    g->width = width;
    g->height = height;
    g->cells = malloc(width * height * sizeof(cell)); // ALLOCATION CORRECTE

    if (g->cells == NULL) {
        free(g);
        return NULL;
    }

    // Initialise all cells
    for (int i = 0; i < width * height; i++) {
        g->cells[i].is_open = false;
        g->cells[i].is_visited = false;
        g->cells[i].row = i / width;
        g->cells[i].col = i % width;
    }

    return g;
}


// Frees the memory allocated for the grid
void free_grid(grid *g) {
    if (g) {
        free(g->cells);
        free(g);
    }
}

// Returns a pointer to a cell at (row, col), or NULL if out of bounds
cell *get_cell(grid *grid, int row, int col) {
    if (row < 0 || row >= grid->height || col < 0 || col >= grid->width) {
        return NULL;
    }
    return &grid->cells[row * grid->width + col];
}


// Updates the state of a cell (open or blocked)
void set_cell(grid *grid, int row, int col, bool is_open) {
    cell *cell = get_cell(grid, row, col);
    if (cell) {
        cell->is_open = is_open;
    }
}

// Prints the grid using '#' for blocked cells and ' ' for open cells
void print_grid(grid *grid) {
    for (int row = 0; row < grid->height; row++) {
        for (int col = 0; col < grid->width; col++) {
            cell *cell = get_cell(grid, row, col);
            if (cell->is_open) {
                printf(" ");  // Open cell
            } else {
                printf("#");  // Blocked cell
            }
        }
        printf("\n");
    }
}

// Generates a PPM image of the grid
void generate_image(grid *grid, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Error: Cannot open file %s for writing.\n", filename);
        return;
    }

    // PPM header
    fprintf(file, "P3\n");  // P3 format (ASCII PPM)
    fprintf(file, "%d %d\n", grid->width, grid->height);
    fprintf(file, "255\n");  // Maximum color value

    // Write pixel data
    for (int row = 0; row < grid->height; row++) {
        for (int col = 0; col < grid->width; col++) {
            cell *cell = get_cell(grid, row, col);
            if (cell->is_open) {
                fprintf(file, "255 255 255 ");  // White (open cell)
            } else {
                fprintf(file, "0 0 0 ");  // Black (blocked cell)
            }
        }
        fprintf(file, "\n");
    }

    fclose(file);
}
