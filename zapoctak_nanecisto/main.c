#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NOT_FOUND_NODE -1
#define FULL_NODE -2
#define GENERAL_CORE_ERROR -3

#define MAX_VAL_B_TREE(l, r) (l->value > r->value) ? l : r

typedef struct b_tree {
    struct b_tree *left;
    struct b_tree *right;

    char *name;
    int value;
} b_tree_t;

b_tree_t *search_name(b_tree_t *tree, const char *name)
{
    if (tree == NULL) {
        return NULL;
    }

    if (!strcmp(tree->name, name)) {
        return tree;
    }

    b_tree_t *tmp = search_name(tree->left, name);

    if (!tmp) {
        tmp = search_name(tree->right, name);
    }

    return tmp;
}

int add_node(b_tree_t *tree, const char *p_name, char *n_name, int val)
{
    b_tree_t *parent = search_name(tree, p_name);

    if (!parent) {
        return NOT_FOUND_NODE;
    }

    if (parent->left && parent->right) {
        return FULL_NODE;
    }

    b_tree_t *tmp = (b_tree_t *) malloc(sizeof(b_tree_t));
    if (!tmp) {
        return GENERAL_CORE_ERROR;
    }

    tmp->name = n_name;
    tmp->value = val;
    tmp->left = NULL;
    tmp->right = NULL;

    if (parent->left) {
        parent->right = tmp;
    } else {
        parent->left = tmp;
    }

    return 0;

}

b_tree_t *get_max_val(b_tree_t *initial)
{
    if (initial == NULL)
        return NULL;

    b_tree_t *max = initial;
    b_tree_t *tmp = get_max_val(initial->left);

    if (tmp) {
        max = MAX_VAL_B_TREE(max, tmp);
    }

    tmp = get_max_val(initial->right);

    if (tmp) {
        max = MAX_VAL_B_TREE(max, tmp);
    }

    return max;
}

void print_tree(b_tree_t *tree, int level)
{
    if (tree == NULL) {
        return;
    }

    if (level == 0) {
        printf("Max node %s, val: %d\n", tree->name, tree->value);
    } else {

        for (int i = 0; i < level; i++) {
            printf("\t");
        }
        printf("%s: %d\n", tree->name, tree->value);
    }
    print_tree(tree->left, level + 1);
    print_tree(tree->right, level + 1);
}

void destroy_tree(b_tree_t *to_d)
{
    if (to_d == NULL) {
        return;
    }

    destroy_tree(to_d->left);
    destroy_tree(to_d->right);

    free(to_d->name);
    free(to_d);
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Illegal amount of arguments\n");
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");

    if (!file) {
        perror(argv[1]);
        return EXIT_FAILURE;
    }

    char buffer[1024] = {'\0'};
    if (fgets(buffer, 1024, file) == 0) {
        fprintf(stderr, "Empty file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    char *token = strtok(buffer, "=\n");
    char *alloc = malloc(1 + strlen(token));

    strcpy(alloc, token);
    token = strtok(NULL, "=\n");

    int val = atoi(token);
    b_tree_t *tree = malloc(sizeof(b_tree_t));

    tree->name = alloc;
    tree->value = val;
    tree->left= NULL;
    tree->right = NULL;

    while (fgets(buffer, 1024, file)) {
        token = strtok(buffer, "=;\n");
        alloc = malloc(1 + strlen(token));
        strcpy(alloc, token);
        token = strtok(NULL, "=;\n");
        val = atoi(token);
        token = strtok(NULL, "=;\n");
        add_node(tree, token, alloc, val);
    }

    b_tree_t *max = get_max_val(tree);

    print_tree(max, 0);
    destroy_tree(tree);
    return 0;
}
