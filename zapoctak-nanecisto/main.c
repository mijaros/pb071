#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"


static char help[] = "\
usage: ./counter [-f FILE_NAME]\n\
This program processes ps output\n\
\t -f \t FILE_NAME uses specified file instead of stdin\n";


void print_help(FILE *where)
{
    fprintf(where, help);
}

int main(int argc, char *argv[])
{
    FILE *input = stdin;

    if (argc > 3) {
        fprintf(stderr, "Too many arguments\n\n");
        print_help(stderr);
        return EXIT_FAILURE;
    }
    if (argc == 2 && !strcmp(argv[1], "-h")) {
        print_help(stdout);
        return EXIT_SUCCESS;
    } else if (argc == 3 && !strcmp(argv[1], "-f")) {
        input = fopen(argv[2], "r");
        if (!input) {
            perror("counter");
            return EXIT_FAILURE;
        }
    } else if (argc != 1) {
        fprintf(stderr, "Invalid argument passed\n\n");
        print_help(stderr);
        return EXIT_FAILURE;
    }

    linked_list_t list;
    linked_list_init(&list);

    parser(&list, input);

    print_stats(&list);

    linked_list_destructor(&list);

    return EXIT_SUCCESS;
}
