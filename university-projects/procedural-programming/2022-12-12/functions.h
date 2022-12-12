#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} node_t;

/* Normal functions used in main.c and functions.c */
void print_user_ui();
bool make_list(node_t **head);
void open_file(FILE **file, char read_mode[]);
void get_filename(char filename_ptr[]);
void add_item(node_t *head, int val);
void print_list(node_t *head);
bool remove_item(node_t **head, int val);
void free_list(node_t *head);

/* Functions used in test.c to test the previous functions */
void make_list_tests();
void test_get_filename();
void test_addition_and_removal();