#include "grid.h"
#include "loader.h"

int main() {
    // Load grid from file
    const char *input_file = "data/grid_np_1.txt";
    grid *grid = load_grid(input_file);
    if (!grid) {
        return 1;
    }

    // Generate image
    const char *output_file = "out/filename.ppm";
    generate_image(grid, output_file);
    printf("Image generated: %s\n", output_file);

    // Free memory
    free_grid(grid);
    return 0;
}
