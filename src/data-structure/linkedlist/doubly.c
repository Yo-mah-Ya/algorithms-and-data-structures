#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

static Node *node = NULL;

Node *create_new_node(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
};

void add_at_first(int data) {
    Node *new_node = create_new_node(data);
    if (node == NULL) {
        node = new_node;
    } else {
        new_node->next = node;
        node->prev = new_node;
        node = new_node;
    }
};

void add_at_last(int data) {
    Node *new_node = create_new_node(data);
    if (node == NULL) {
        node = new_node;
        return;
    }

    Node *head = node;
    while (head->next != NULL) {
        head = head->next;
    }
    new_node->prev = head;
    head->next = new_node;
};

void delete_at_first() {
    if (node == NULL) {
        return;
    }
    Node *head = node;
    node = node->next;
    node->prev = NULL;
    free(head);
}

void delete_at_last() {
    if (node == NULL) {
        return;
    }
    Node *head = node;
    Node *prev = node;
    while (head->next != NULL) {
        prev = head;
        head = head->next;
    }
    prev->next = NULL;
    free(head);
}

void delete_all() { node = NULL; }

int is_circular(Node *node) {
    if (node == NULL) {
        return 1;
    }
    Node *head = node->next;
    while (head != NULL && head != node) {
        head = head->next;
    }
    return head == node;
}

void show_all_data_separately(char *operation_name) {
    printf("%s\n", operation_name);
    Node *head = node;
    int index = 0;
    while (head != NULL) {
        printf("index: %d, data: %-2d, prev: %-11p, head: %-11p, next: %-11p\n",
               index, head->data, head->prev, head, head->next);
        head = head->next;
        index++;
    }
    free(head);
    printf("\n");
}

void reverse() {
    Node *prev = NULL;
    Node *current = node;
    Node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }
    node = prev;
}

int main(int argc, char const *argv[]) {
    add_at_first(1);
    add_at_first(2);
    add_at_first(3);
    show_all_data_separately("add_at_first");

    reverse();
    show_all_data_separately("reverse");

    add_at_last(4);
    show_all_data_separately("add_at_last");

    delete_at_first();
    show_all_data_separately("delete_at_first");

    delete_at_last();
    show_all_data_separately("delete_at_last");

    delete_all();
    show_all_data_separately("delete_all");

    delete_all();
    add_at_last(1);
    add_at_last(2);
    add_at_last(3);
    assert(is_circular(node) == 0);
    node->next->next = node;
    assert(is_circular(node) == 1);
    return 0;
}
