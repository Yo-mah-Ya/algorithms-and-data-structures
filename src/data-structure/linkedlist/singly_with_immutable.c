#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *create_new_node(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
};

void show_all_data_separately(Node *node, char *operation_name) {
    printf("%s\n", operation_name);
    if (node == NULL) {
        return;
    }
    Node *head = node;
    int index = 0;
    while (head != NULL) {
        printf("index: %d, data: %-2d, head: %-11p, next: %-11p\n", index,
               head->data, head, head->next);
        head = head->next;
        index++;
    }
    free(head);
    printf("\n");
}

Node *reverse(Node *node) {
    Node *prev = NULL;
    Node *current = node;
    Node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main(int argc, char const *argv[]) {
    // This program always adds node at the very env of the node.
    // "current" always points the last node, and the other hand "node" points
    // the head.

    Node node = {};
    Node *current = &node;
    Node *resultNode;
    /**
     * add_at_first
     */
    current = current->next = create_new_node(1);
    current = current->next = create_new_node(2);
    current = current->next = create_new_node(3);
    resultNode = node.next;
    show_all_data_separately(resultNode, "add_at_first");
    assert(resultNode->data == 1 && resultNode->next->data == 2 &&
           resultNode->next->next->data == 3 &&
           resultNode->next->next->next == NULL);

    /**
     * reverse
     */
    resultNode = reverse(node.next);
    show_all_data_separately(resultNode, "reverse");
    assert(resultNode->data == 3 && resultNode->next->data == 2 &&
           resultNode->next->next->data == 1 &&
           resultNode->next->next->next == NULL);

    return 0;
}
