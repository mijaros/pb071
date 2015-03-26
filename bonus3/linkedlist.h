/**
 * Simple linked list interface
 * Created as study material for C course pb071 at FI MU
 */
#ifndef LINKED_LIST_H
#define LINKED_LIST_H



struct item_t {
    char *data;
    struct item_t *next;
}

struct linked_list {
    struct item_t *first;
    struct item_t *last;
    size_t size;
}

typedef linked_list linked_list_t;

/**
 * @brief Initialise the list eq sets values to 0x0
 *
 * @param list pointer to list which will be initialised
 * @return 0 on success, this function should not fail at any
 * circumstances
 */
int init_linked_list(linked_list_t *list);

/**
 * @brief puts data as last item in the list
 *
 * @param list List where data will be stored
 * @param data data to store
 *
 * @return 0 on success negative value on fail
 * read the macros
 */
int push_back(linked_list_t *list, char *data);

/**
 * @brief puts data as first item in list
 *
 * @param list List where data will be stored
 * @param data data to store
 *
 * @return 0 on success negative value otherwise
 */
int push_front(linked_list_t *list, char *data);

/**
 * @brief inserts
 */
int insert_to(linked_list_t *list, char *data, size_t index);

char *back(linked_list_t *list);

char *front(linked_list_t *list);

char *at_index(linked_list_t *list, size_t index);

char *pop_back(linked_list_t *list);

char *pop_front(linked_list_t *list);


#endif /*LINKED_LIST_H*/
