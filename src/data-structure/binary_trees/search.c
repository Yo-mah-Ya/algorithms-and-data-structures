#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *left;
    struct Node *right;
    int data;
} Node;

Node *create_new_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node *insert(Node *root, int data) {
    if (root == NULL) {
        root = create_new_node(data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    }
    return root;
}

Node *getMax(Node *root) {
    if (root->right != NULL) {
        return getMax(root->right);
    }
    return root;
}

Node *delete(Node *root, int data) {
    if (root == NULL) {
        return root;
    } else if (data > root->data) {
        root->right = delete (root->right, data);
    } else if (data < root->data) {
        root->left = delete (root->left, data);
    } else if (data == root->data) {
        // Case 1: the root has no leaves, remove the node
        if ((root->left == NULL) && (root->right == NULL)) {
            free(root);
            return NULL;
            // Case 2: the root has one leaf, make the leaf the new root and
            // remove the old root
        } else if (root->left == NULL) {
            Node *tmp = root;
            root = root->right;
            free(tmp);
            return root;
        } else if (root->right == NULL) {
            Node *tmp = root;
            root = root->left;
            free(tmp);
            return root;
        } else {
            // Case 3: the root has 2 leaves, find the greatest key in the
            // left subtree and switch with the root's finds the biggest node in
            // the left branch.
            Node *tmp = getMax(root->left);

            // sets the data of this node equal to the data of the biggest node
            // (lefts)
            root->data = tmp->data;
            root->left = delete (root->left, tmp->data);
        }
    }
    return root;
}

bool find(Node *root, int data) {
    if (root == NULL) {
        return false;
    } else if (data > root->data) {
        return find(root->right, data);
    } else if (data < root->data) {
        return find(root->left, data);
    } else if (data == root->data) {
        return true;
    } else {
        return false;
    }
}

int height(Node *root) {
    if (root == NULL) {
        return 0;
    } else {
        // Get the height from both left and right subtrees to check which is
        // the greatest
        int right_h = height(root->right);
        int left_h = height(root->left);

        // The final height is the height of the greatest subtree(left or right)
        // plus 1(which is the root's level)
        if (right_h > left_h) {
            return (right_h + 1);
        } else {
            return (left_h + 1);
        }
    }
}

void purge(Node *root) {
    if (root != NULL) {
        if (root->left != NULL) {
            purge(root->left);
        }
        if (root->right != NULL) {
            purge(root->right);
        }
        free(root);
        root = NULL;
    }
}

void in_order(Node *root) {
    if (root != NULL) {
        in_order(root->left);
        printf("[ %d ]\n", root->data);
        in_order(root->right);
    }
}

int main(int argc, char const *argv[]) {
    Node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    find(root, 3) ? printf("The value is in the tree.\n")
                  : printf("The value is not in the tree.\n");
    printf("Current height of the tree is: %d\n", height(root));
    in_order(root);
    delete (root, 3);
    in_order(root);
    return 0;
}
