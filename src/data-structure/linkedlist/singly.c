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

void add_at_first(Node **node, int data) {
    Node *new_node = create_new_node(data);
    if (*node == NULL) {
        *node = new_node;
    } else {
        new_node->next = *node;
        *node = new_node;
    }
};

void add_at_last(Node **node, int data) {
    Node *new_node = create_new_node(data);
    if (*node == NULL) {
        *node = new_node;
        return;
    }

    Node *head = *node;
    while (head->next != NULL) {
        head = head->next;
    }
    head->next = new_node;
};

void delete_at_first(Node **node) {
    if (*node == NULL) {
        return;
    }
    Node *head = *node;
    *node = (*node)->next;
    free(head);
}

void delete_at_last(Node *node) {
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

void delete_all(Node **node) { *node = NULL; }

void deleteNthNodeListFromEnd(Node **node, int n) {
    if (*node == NULL) {
        return;
    }
    Node *iter = *node;
    int len = 0, i = 1;
    while (iter != NULL) {
        iter = iter->next;
        len++;  // finding the length of linked list
    }
    if (len == n) {
        *node =
            (*node)->next;  // if head itself is to be deleted, just return head
                            // -> next
        return;
    }
    for (iter = *node; i < len - n; i++) {
        iter = iter->next;  // iterate first len-n nodes
    }
    iter->next = iter->next->next;  // remove the nth node from the end
}

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

void show_all_data_separately(Node **node, char *operation_name) {
    printf("%s\n", operation_name);
    if (*node == NULL) {
        return;
    }
    Node *head = *node;
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

void reverse(Node **node) {
    Node *prev = NULL;
    Node *current = *node;
    Node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *node = prev;
}

Node *merge_two_nodes(Node **node1, Node **node2) {
    if (*node1 == NULL)
        return *node2;
    if (*node2 == NULL)
        return *node1;

    Node head = {};
    Node *current = &head;
    while (*node1 != NULL && *node2 != NULL) {
        if ((*node1)->data <= (*node2)->data) {
            current->next = *node1;
            *node1 = (*node1)->next;
        } else {
            current->next = *node2;
            *node2 = (*node2)->next;
        }
        current = current->next;
    }
    if (*node1 == NULL) {
        current->next = *node2;
    } else {
        current->next = *node1;
    }
    return head.next;
}

int main(int argc, char const *argv[]) {
    Node *node = NULL;

    /**
     * add_at_first
     */
    add_at_first(&node, 1);
    add_at_first(&node, 2);
    add_at_first(&node, 3);
    show_all_data_separately(&node, "add_at_first");
    assert(node->data == 3 && node->next->data == 2 &&
           node->next->next->data == 1 && node->next->next->next == NULL);

    /**
     * reverse
     */
    reverse(&node);
    show_all_data_separately(&node, "reverse");
    assert(node->data == 1 && node->next->data == 2 &&
           node->next->next->data == 3 && node->next->next->next == NULL);

    /**
     * add_at_last
     */
    add_at_last(&node, 4);
    show_all_data_separately(&node, "add_at_last");
    assert(node->data == 1 && node->next->data == 2 &&
           node->next->next->data == 3 && node->next->next->next->data == 4 &&
           node->next->next->next->next == NULL);

    /**
     * delete_at_first
     */
    delete_at_first(&node);
    show_all_data_separately(&node, "delete_at_first");
    assert(node->data == 2 && node->next->data == 3 &&
           node->next->next->data == 4 && node->next->next->next == NULL);

    /**
     * delete_at_last
     */
    delete_at_last(node);
    show_all_data_separately(&node, "delete_at_last");
    assert(node->data == 2 && node->next->data == 3 &&
           node->next->next == NULL);

    /**
     * delete_all
     */
    delete_all(&node);
    show_all_data_separately(&node, "delete_all");
    assert(node == NULL);

    /**
     * deleteNthNodeListFromEnd
     */
    add_at_last(&node, 1);
    add_at_last(&node, 2);
    add_at_last(&node, 3);
    add_at_last(&node, 4);
    add_at_last(&node, 5);
    deleteNthNodeListFromEnd(&node, 2);
    show_all_data_separately(&node, "1: deleteNthNodeListFromEnd");
    assert(node->data == 1 && node->next->data == 2 &&
           node->next->next->data == 3 && node->next->next->next->data == 5 &&
           node->next->next->next->next == NULL);
    delete_all(&node);  // reset
    add_at_last(&node, 1);
    deleteNthNodeListFromEnd(&node, 1);
    show_all_data_separately(&node, "2: deleteNthNodeListFromEnd");
    assert(node == NULL);
    delete_all(&node);  // reset
    add_at_last(&node, 1);
    add_at_last(&node, 2);
    deleteNthNodeListFromEnd(&node, 1);
    show_all_data_separately(&node, "3: deleteNthNodeListFromEnd");
    assert(node->data == 1 && node->next == NULL);

    /**
     * is_circular
     */
    delete_all(&node);
    add_at_last(&node, 1);
    add_at_last(&node, 2);
    add_at_last(&node, 3);
    assert(is_circular(node) == 0);
    node->next->next = node;
    assert(is_circular(node) == 1);

    /**
     * merge_two_nodes
     */
    Node *node1 = NULL;
    add_at_last(&node1, 1);
    add_at_last(&node1, 2);
    add_at_last(&node1, 4);
    Node *node2 = NULL;
    add_at_last(&node2, 1);
    add_at_last(&node2, 3);
    add_at_last(&node2, 4);
    node = merge_two_nodes(&node1, &node2);
    show_all_data_separately(&node, "merge_two_nodes");
    assert(node->data == 1 && node->next->data == 1 &&
           node->next->next->data == 2 && node->next->next->next->data == 3 &&
           node->next->next->next->next->data == 4 &&
           node->next->next->next->next->next->data == 4 &&
           node->next->next->next->next->next->next == NULL);
    return 0;
}
