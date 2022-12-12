#include <assert.h>
#include <conio.h>
#include <functions.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    system("cls");
    node_t *head = NULL;
    head = (node_t *)malloc(sizeof(node_t));
    head->next = NULL;

    assert(head != NULL);

    bool list_made = false;
    char command;
    int val;

    print_user_ui();
    for (;;) {
        if (kbhit()) {
            command = getch();
            if (command >= '1' && command <= '4') {
                switch (command) {
                    case '1':
                        if (list_made) {
                            printf("Can't create list again!\n");
                            break;
                        } else {
                            if (make_list(&head) == false) {
                                printf("Failed to make list. Terminating program.\n");
                                exit(0);
                            } else {
                                printf("Successfully created list.\n");
                                print_user_ui();
                                list_made = true;
                                break;
                            }
                        }
                    case '2':
                        if (!list_made) {
                            printf("First create a list. Can't print an empty list.\n");
                            break;
                        } else {
                            system("cls");
                            printf("Item list:\n");
                            print_list(head);
                            print_user_ui();
                            break;
                        }
                    case '3':
                        if (!list_made) {
                            printf("First create a list. Can't remove an element from an empty list.\n");
                            break;
                        } else {
                            for (;;) {
                                printf("Enter value to remove: ");
                                if (scanf("%d", &val) == 1 && getchar() == '\n') {
                                    system("cls");
                                    if (remove_item(&head, val) == true) {
                                        printf("Element %d removed successfully.\n", val);
                                        break;
                                    } else {
                                        printf("Element %d does not exist in the list.\n", val);
                                        break;
                                    }
                                } else {
                                    printf("Invalid input. Try again.\n");
                                    while (getchar() != '\n')
                                        ;
                                }
                            }
                            print_user_ui();
                            break;
                        }
                    case '4':
                        free_list(head);
                        return 0;
                }
            }
        }
    }
}