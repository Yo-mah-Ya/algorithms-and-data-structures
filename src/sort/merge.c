#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

/**
 * @brief Perform merge of segments.
 *
 * @param a array to sort
 * @param l left index for merge
 * @param r right index for merge
 * @param n total number of elements in the array
 */
void merge(int *a, int l, int r, int n) {
    int *b = (int *)malloc(n * sizeof(int));
    if (b == NULL) {
        fprintf(stderr, "Can't Malloc! Please try again.");
        exit(EXIT_FAILURE);
    }
    int c = l;
    int p1, p2;
    p1 = l;
    p2 = ((l + r) / 2) + 1;
    while ((p1 < ((l + r) / 2) + 1) && (p2 < r + 1)) {
        if (a[p1] <= a[p2]) {
            b[c++] = a[p1];
            p1++;
        } else {
            b[c++] = a[p2];
            p2++;
        }
    }

    if (p2 == r + 1) {
        while ((p1 < ((l + r) / 2) + 1)) {
            b[c++] = a[p1];
            p1++;
        }
    } else {
        while ((p2 < r + 1)) {
            b[c++] = a[p2];
            p2++;
        }
    }

    for (c = l; c < r + 1; c++) {
        a[c] = b[c];
    }

    free(b);
}

/** Merge sort algorithm implementation
 * @param a array to sort
 * @param n number of elements in the array
 * @param l index to sort from
 * @param r index to sort till
 */
void merge_sort(int *a, int n, int l, int r) {
    if (r - l == 1) {
        if (a[l] > a[r])
            swap(&a[l], &a[r]);
    } else if (l != r) {
        merge_sort(a, n, l, (l + r) / 2);
        merge_sort(a, n, ((l + r) / 2) + 1, r);
        merge(a, l, r, n);
    }
}

int main(void) {
    int a[] = {10, 5, 3, 8, 2, 6, 4, 7, 9, 1};
    int n = sizeof(a) / sizeof(a[0]);

    merge_sort(a, n, 0, n - 1);
    for (size_t i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
