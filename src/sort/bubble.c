#include <assert.h>
#include <stdbool.h>

void bubble_sort(int arr[], int length) {
    for (int i = 0; i < length - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < length - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                const int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
};

int main(int argc, char const *argv[]) {
    int arr[] = {5, 4, 1, 2, 3};
    int expected[] = {1, 2, 3, 4, 5};
    int length = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, length);
    for (int i = 0; i < 5; i++) {
        assert(arr[i] == expected[i]);
    }

    return 0;
}
