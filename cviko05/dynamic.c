/**
 * This program reads command line arguments and
 * prints them to standard output sorted alphabetically
 * with preceding order.
 *
 * @author Miroslav Jaros
 * @email xjaros1@fi.muni.cz
 * @version 0.1
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * @brief Comparator for qsort
 * This function is created for compare of two strings and is meant to be used
 * with qsort as its comparator
 * Parameters are pointers to values in array, therefore theirs type is char **
 *
 * @param ptr1 Pointer to left string in unsorted array
 * @param ptr2 Pointer to right string in unsorted array
 *
 * @return 0 if strings are same >1 if left value is bigger by alphabetical order <1 otherwise
 */
int compare_strings(const void *ptr1, const void *ptr2);

static char help[] = "\
Usage: dynamic arg1 [args]\n\
Print arguments in alphabetical order.\n\
\
";

int main(int argc, char *argv[])
{
    if (argc <= 1) {
        fprintf(stderr, "Illegal amount of arguments\n");
        printf("%s\n", help);
        return EXIT_FAILURE;
    }
    char **array = NULL;

    array = (char **) malloc((argc-1) * sizeof(char *) + 1);
    if(!array) {
        perror("malloc");
        return EXIT_FAILURE;
    }
    memset((void *) array, 0x0, sizeof(char **) * (argc - 1));

    for (int i = 0; i < argc - 1; i++) {
        if (argv[i] == NULL) {
            break;
        }

        int len = strlen(argv[i + 1]);

        array[i] = (char *) malloc(len + 1);
        if (!array[i]) {
            perror("malloc");
            return EXIT_FAILURE;
        }

        strcpy(array[i], argv[i + 1]);
    }

    qsort(array, argc - 1, sizeof(char *), compare_strings);

    for (int i = 0; i < argc - 1; i++) {
        if (!array[i]) {
            break;
        }

        printf("%d. %s\n", i + 1, array[i]);
        free(array[i]);
        array[i] = NULL;
    }
    free(array);
    return EXIT_SUCCESS;
}

int compare_strings(const void *ptr1, const void *ptr2)
{
    return strcmp( *(const char **) ptr1, *(const char **) ptr2);
}
