#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    char *command;
    int pid;
    double cpu;
    double mem;
    int proc_time;
    char user_name[255];
} process_t;

typedef struct node {
    struct node * next;
    process_t *data;
} node_t;

typedef struct {
    node_t *head;
    node_t *end;
    size_t size;
} linked_list_t;

typedef struct {
    char *user_name;
    double total_mem;
    double total_cpu;
    int total_time;
} user_info;

void linked_list_init(linked_list_t *list);

int linked_list_add(linked_list_t *list, process_t *data);

void linked_list_destructor(linked_list_t *list);

void print_stats(linked_list_t *list);

int parser(linked_list_t *list, FILE *from);

#endif
