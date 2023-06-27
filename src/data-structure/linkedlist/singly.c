#include<stdio.h>
#include<stdlib.h>
#include <assert.h>


typedef struct Node {
    int data;
    struct Node *next;
} Node;

static Node *node = NULL;

Node *create_new_node(int data)
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
};

void add_at_first(int data)
{
    Node *new_node =create_new_node(data);
    if(node == NULL){
        node = new_node;
    }else {
        new_node->next = node;
        node = new_node;
    }
};

void add_at_last(int data)
{
    Node *new_node =create_new_node(data);
    if(node == NULL){
        node = new_node;
        return;
    }

    Node *head = node;
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = new_node;
};

void delete_at_first()
{
    if(node == NULL){
        return;
    }
    Node *head = node;
    node = node->next;
    free(head);
}

void delete_at_last()
{
    if(node == NULL){
        return;
    }
    Node *head = node;
    Node *prev = node;
    while(head->next != NULL){
        prev = head;
        head = head->next;
    }
    prev->next = NULL;
    free(head);
}


void delete_all()
{
    node = NULL;
}

void deleteNthNodeListFromEnd(int n)
{
    if(node == NULL){
        return;
    }
    Node* iter = node;
	int len = 0, i = 1;
	while(iter != NULL) {
        iter = iter->next;
        len++;    // finding the length of linked list
    }
	if(len == n) {
        node = node->next;          // if head itself is to be deleted, just return head -> next
        return;
    }
	for(iter = node; i < len - n; i++) {
        iter = iter->next; // iterate first len-n nodes
    }
	iter->next = iter->next->next;      // remove the nth node from the end
}

void show_all_data_separately(char *operation_name)
{
    printf("%s\n", operation_name);
    Node *head = node;
    int index = 0;
    while(head != NULL){
        printf("index: %d, data: %d, next: %p\n",index, head->data, head->next);
        head = head->next;
        index++;
    }
    free(head);
    printf("\n");
}


void reverse()
{
    Node *prev = NULL;
    Node *current = node;
    Node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    node = prev;
}

int main(int argc, char const *argv[])
{
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


    add_at_last(1);
    add_at_last(2);
    add_at_last(3);
    add_at_last(4);
    add_at_last(5);
    deleteNthNodeListFromEnd(2);
    show_all_data_separately("1: deleteNthNodeListFromEnd");
    delete_all(); // reset
    add_at_last(1);
    deleteNthNodeListFromEnd(1);
    show_all_data_separately("2: deleteNthNodeListFromEnd");
    delete_all(); // reset
    add_at_last(1);
    add_at_last(2);
    deleteNthNodeListFromEnd(1);
    show_all_data_separately("3: deleteNthNodeListFromEnd");


    return 0;
}
