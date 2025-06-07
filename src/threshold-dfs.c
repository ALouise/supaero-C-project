#include <stdio.h>
#include <stdlib.h>
#include "simulation_dfs.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <width> <height> <num_simulations>\n", argv[0]);
        return 1;
    }

    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    int num_simulations = atoi(argv[3]);
    int seed = 1024;  // Default seed

    srand(seed);

    printf("Running %d Monte Carlo simulations on a %dx%d grid...\n", num_simulations, width, height);

    int total_open_cells = 0;
    for (int i = 1; i <= num_simulations; i++) {
        int open_cells = monte_carlo_simulation(width, height, i);  
        printf("Simulation %d: Opened %d cells\n", i, open_cells);
        total_open_cells += open_cells;
    }

    double threshold = (double)total_open_cells / (num_simulations * width * height);
    printf("Estimated percolation threshold: %.3f\n", threshold);
    
    return 0;
}
