#include "loader.h"

int main() {
    const char *filename = "data/grid_np_5.txt";
    
    // Load grid from file
    grid *grid = load_grid(filename);
    if (!grid) {
        return 1;
    }

    // Print loaded grid
    print_grid(grid);

    // Free memory
    free_grid(grid);

    return 0;
}
