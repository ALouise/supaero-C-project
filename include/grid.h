#ifndef GRID_H
#define GRID_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// A single cell in the grid
typedef struct {
    int row, col;
    bool is_open;
    bool is_visited;
} cell;

// The full grid structure
typedef struct {
    int width, height;
    cell *cells;
} grid;

// Creates a new grid with all cells closed
grid *create_grid(int width, int height);

// Frees a grid from memory
void free_grid(grid *grid);

// Returns a pointer to the cell at (row, col)
cell *get_cell(grid *grid, int row, int col);

// Opens or closes a cell
void set_cell(grid *grid, int row, int col, bool is_open);

// Prints the grid to stdout
void print_grid(grid *grid);

// Saves a visual representation of the grid as a PPM image
void generate_image(grid *grid, const char *filename);

#endif // GRID_H
