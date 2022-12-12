#include <assert.h>
#include <conio.h>
#include <functions.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    system("cls");
    make_list_tests();
    test_get_filename();
    test_addition_and_removal();
    exit(0);
}

void make_list_tests() {
    printf("Testing the make_list function.\n\n");
    // 1st test - empty input file
    node_t *head = NULL;
    assert(make_list(&head) == false);
    assert(head == NULL);
    printf("Test 1 passed.\n");

    // 2nd test - only one number in file
    head = (node_t *)malloc(sizeof(node_t));
    head->next = NULL;

    make_list(&head);
    assert(head != NULL);
    assert(head->next == NULL);
    printf("\nTest 2 passed.\n");

    // 3rd test - 2 numbers in file
    free_list(head);
    node_t *head2 = (node_t *)malloc(sizeof(node_t));
    head2->next = NULL;

    make_list(&head2);
    assert(head2 != NULL);
    assert(head2->next != NULL);
    assert(head2->next->next == NULL);
    free_list(head2);
    printf("\nTest 3 passed.\n");

    // 4th test - non-integer in file
    node_t *head3 = (node_t *)malloc(sizeof(node_t));
    head3->next = NULL;

    assert(make_list(&head3) == false);
    printf("Test 4 passed.\n");

    printf("\nAll tests passed.");
    return;
}

void test_get_filename() {
    printf("Testing the get_filename function.\n\n");
    // Array for filename
    char *filename_ptr = (char *)malloc(sizeof(char));
    assert(filename_ptr != NULL);

    // Example input that will be tested
    char *user_input = "my_data_file.txt";

    // Call the function
    get_filename(filename_ptr);

    // 1st test - pointer isn't null
    assert(filename_ptr != NULL);
    printf("\nTest 1 passed.\n");

    // 2nd test - the read string is the same size as expected
    printf("Test 2 passed.\n");

    // 3rd test - string has a \0 at the end
    assert(filename_ptr[strlen(filename_ptr)] == '\0');
    printf("Test 3 passed.\n");
    printf("\nAll tests passed.\n");

    // Clean up
    free(filename_ptr);
    fclose(stdin);
}

void test_addition_and_removal() {
    printf("\nTesting the add_item and remove_item functions.\n");
    node_t *head = NULL;
    head = (node_t *)malloc(sizeof(node_t));
    head->next = NULL;

    assert(head != NULL);

    head->val = 5;

    // Test 1 - add one value
    add_item(head, 7);
    assert(head->next->val == 7);
    assert(head->next->next == NULL);
    printf("Test 1 passed.\n");

    // Test 2 - add multiple values
    for (int i = 1; i <= 2; ++i) {
        add_item(head, i * i);
    }
    assert(head->next->next->val == 1);
    assert(head->next->next->next != NULL);
    assert(head->next->next->next->val == 4);
    assert(head->next->next->next->next == NULL);
    printf("Test 2 passed.\n");

    // Test 3 - function removal
    assert(remove_item(&head, 348395) == false);
    assert(remove_item(&head, 1) == true);
    assert(head->next->next->val == 4);
    assert(head->next->next->next == NULL);
    printf("Test 3 passed.\n");

    printf("All tests passed.\n");
}