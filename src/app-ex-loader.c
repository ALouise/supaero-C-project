/**
 * A simple program to load a grid data file and "print" it on the
 * console
 *
 * Ex. of usage:
 *
 * ./app-ex-loader ./data/grid_visited.txt
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // testing if a filename has been given
    if (argc != 2) {
        fprintf(stderr, "You must provide a file name!\n");
        exit(EXIT_FAILURE);
    }

    // open file. The filename is the first argument on the command
    // line, hence stored in argv[1]
    FILE *p_file = NULL;

    p_file = fopen(argv[1], "r");

    if (p_file == NULL) {
        fprintf(stderr, "Cannot read file %s!\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // read dimensions on first line
    int width         = 0;
    int height        = 0;
    int sscanf_result = 0;

    char first_line_buffer[100];

    if (fgets(first_line_buffer, 100, p_file) == NULL) {
        fprintf(stderr, "fgets error at first line!\n");
        exit(EXIT_FAILURE);
    }

    sscanf_result = sscanf(first_line_buffer, "%d %d", &width, &height);

    if (sscanf_result != 2) {
        fprintf(stderr, "First line is not syntactically correct!\n");
        exit(EXIT_FAILURE);
    }

    printf("grid dimensions: %d x %d\n", width, height);

    // read following lines
    // line_buffer contains a line and is a correct string
    // width + 2 is needed to get the carriage return symbol
    char line_buffer[width + 2];

    for (int l = 0; l < height; l++) {
        if (fgets(line_buffer, width + 2, p_file) == NULL) {
            fprintf(stderr, "fgets error at line %d!\n", l);
            exit(EXIT_FAILURE);
        }

        printf("line %d: %s", l, line_buffer);
    }

    fclose(p_file);

    return EXIT_SUCCESS;
}
