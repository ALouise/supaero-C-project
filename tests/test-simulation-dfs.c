#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "simulation_dfs.h"
#include "grid.h"

int main() {
    printf("Running Monte Carlo simulation tests...\n");

    int expected_results[] = {52997, 53410, 54173, 53625, 53087,
                              52842, 53947, 53138, 53335, 53953};

    int width = 300, height = 300, seed = 1024;
    
    srand(seed);

    for (int i = 1; i <= 10; i++) {
        int result = monte_carlo_simulation(width, height, i); // enlever seed ici
        printf("Simulation %d: Opened %d cells\n", i, result);
        printf("Simulation %d: Expected %d, Got %d\n", i, expected_results[i-1], result);
        assert(result == expected_results[i-1]);
    }

    printf("All Monte Carlo tests passed!\n");
    return 0;
}

