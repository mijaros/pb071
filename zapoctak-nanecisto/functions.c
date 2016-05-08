#include "functions.h"

#include <string.h>
#include <stdint.h>
#include <ctype.h>

#define BUFFER_LEN 2048

static char delimiters[] = " \t\v\f";

static user_info *get_by_name(user_info *array, char *name, size_t count)
{
    for (size_t i = 0; i < count; i++) {
        if (strcmp(array[i].user_name, name) == 0) {
            return &array[i];
        }
    }
    return NULL;
}

static int get_proc_time(char *data)
{
    int hours = atoi(data);
    int minutes = atoi(strchr(data,':') + 1);
    return minutes + 60 * hours;
}

void linked_list_init(linked_list_t *list)
{
    if (!list) {
        return;
    }
    list->head = NULL;
    list->end = NULL;
    list->size = 0;
}

int linked_list_add(linked_list_t *list, process_t *data)
{
    if (!list) {
        return EXIT_FAILURE;
    }

    node_t *new_process = (node_t *) malloc(sizeof(node_t));
    new_process->data = data;
    new_process->next = NULL;

    if (list->head) {
        list->end->next = new_process;
        list->end = new_process;
    } else {
        list->head = new_process;
        list->end = new_process;
    }

    return EXIT_SUCCESS;
}

void linked_list_destructor(linked_list_t *list)
{
    if (!list) {
        return;
    }

    node_t *tmp = list->head;

    while (tmp) {
        node_t *to_del = tmp;
        tmp = tmp->next;
        free(to_del->data->command);
        free(to_del->data);
        free(to_del);
    }
    linked_list_init(list);
}

void print_stats(linked_list_t *list)
{
    user_info *users = (user_info *) calloc(sizeof(user_info), 100);
    size_t found_names = 0;
    node_t *tmp = list->head;
    node_t *highest_cpu = tmp;
    node_t *highest_mem = tmp;
    while (tmp) {
        if (tmp->data->cpu > highest_cpu->data->cpu) {
            highest_cpu = tmp;
        }

        if (tmp->data->mem > highest_mem->data->mem) {
            highest_mem = tmp;
        }

        user_info *target = get_by_name(users, tmp->data->user_name, found_names);
        if (target == NULL) {
            target = &users[found_names];
            target->user_name = tmp->data->user_name;
            target->total_mem = 0;
            target->total_cpu = 0;
            target->total_time = 0;
            found_names++;
        }
        target->total_time += tmp->data->proc_time;
        target->total_cpu += tmp->data->cpu;
        target->total_mem += tmp->data->mem;
        tmp = tmp->next;
    }

    printf("Highest cpu usage had %d, %s\n", highest_cpu->data->pid, highest_cpu->data->command);
    printf("Highest memory usage had %d, %s\n", highest_mem->data->pid, highest_mem->data->command);
    for (size_t j = 0; j < found_names; j++) {
        printf("\t%s: CPU=%f, MEM=%f, TIME=%d\n", users[j].user_name, users[j].total_cpu, users[j].total_mem, users[j].total_time);
    }

    free(users);
}

int parser(linked_list_t *list, FILE *from)
{
    char buffer[BUFFER_LEN] = "";
    int i = 0;
    while (fgets(buffer, BUFFER_LEN, from)) {
        if (i == 0) {
            i++;
            continue;
        }
        char *ptr = buffer;
        char *end_ptr = strpbrk(buffer, delimiters);
        int j = 0;
        process_t *curr_line = (process_t *) malloc(sizeof(process_t));
        while (ptr) {
            if (isspace(ptr[0])) {
                continue;
            }
            switch (j) {
            case 0:
                strncpy(curr_line->user_name, ptr, end_ptr - ptr);
                curr_line->user_name[end_ptr - ptr] = '\0';
                break;
            case 1:
                curr_line->pid = atoi(ptr);
                break;
            case 2:
                curr_line->cpu = strtod(ptr, NULL);
                break;
            case 3:
                curr_line->mem = strtod(ptr, NULL);
                break;
            case 9:
                curr_line->proc_time = get_proc_time(ptr);
                break;
            case 10:
                curr_line->command = (char *) malloc(strlen(ptr));
                if (curr_line->command == NULL) {
                    perror("error");
                    exit(-12);
                }
                strncpy(curr_line->command, ptr, strlen(ptr) - 1);
                curr_line->command[strlen(ptr) - 1] = '\0';

            }
            if (j == 10) {
                break;
            }
            do {
                ptr = end_ptr + 1;
                end_ptr = strpbrk(ptr, delimiters);
            } while (isspace(ptr[0]));
            j++;
        }
        linked_list_add(list, curr_line);
        i++;

    }
    return EXIT_SUCCESS;
}
