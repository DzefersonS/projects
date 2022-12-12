#include <assert.h>
#include <conio.h>
#include <functions.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void print_user_ui() {
    printf("Press 1 if you want to create a list from a data file.\n");
    printf("Press 2 if you want to print the list.\n");
    printf("Press 3 if you want to delete a value from the list.\n");
    printf("Press 4 if you want to exit the program.\n");
}

bool make_list(node_t **head) {
    bool empty_head = true;
    FILE *fp = NULL;
    open_file(&fp, "r");

    int empty_file = fgetc(fp);

    if (empty_file == EOF) {
        fclose(fp);
        printf("Empty file.\n");
        return false;
    } else {
        ungetc(empty_file, fp);
    }

    int val;
    char temp;

    for (;;) {
        if (fscanf(fp, "%d", &val) == 1) {
            if (empty_head) {
                (*head)->val = val;
                empty_head = false;
            } else {
                add_item(*head, val);
            }
            temp = fgetc(fp);
            if (temp == EOF) {
                fclose(fp);
                return true;
            }
        } else {
            printf("Invalid data detected in input file.\n");
            return false;
        }
    }
}

void open_file(FILE **file, char read_mode[]) {
    char *filename_ptr = (char *)malloc(sizeof(char));
    assert(filename_ptr != NULL);
    while (1) {
        get_filename(filename_ptr);
        *file = fopen(filename_ptr, read_mode);
        if (*file == NULL) {
            printf("Failed to open file. Try again.\n");
            fclose(*file);
        } else {
            free(filename_ptr);
            return;
        }
    }
}

void get_filename(char filename_ptr[]) {
    char temp;
    int char_count = 0;

    printf("Enter the name of the data file:\n");

    while ((temp = getchar()) != '\n') {
        char_count++;
        realloc(filename_ptr, char_count * sizeof(char));
        *(filename_ptr + (char_count - 1)) = temp;
    }

    char_count++;
    realloc(filename_ptr, char_count * sizeof(char));
    *(filename_ptr + (char_count - 1)) = '\0';

    return;
}

void add_item(node_t *head, int val) {
    node_t *current = head;
    if (current->next != NULL) {
        return add_item(current->next, val);
    }

    current->next = (node_t *)malloc(sizeof(node_t));
    assert(current->next != NULL);
    current->next->val = val;
    current->next->next = NULL;
    return;
}

void print_list(node_t *head) {
    node_t *current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }

    int command;

    printf("Press 0 once you're done reading the list.\n");
    for (;;) {
        if (kbhit()) {
            if ((command = getch()) == '0') {
                return;
            }
        }
    }
    return;
}

void free_list(node_t *head) {
    node_t *current = head;
    node_t *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

bool remove_item(node_t **head, int val) {
    node_t *curr = *head;
    if (!curr) {
        return false;
    }

    if (curr->val == val) {
        *head = curr->next;
        free(curr);
        return true;
    }

    return remove_item(&curr->next, val);
}