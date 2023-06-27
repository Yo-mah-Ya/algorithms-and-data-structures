#include<stdio.h>
#include<stdalign.h>
#include<stdbool.h>
#include<math.h>
#include<assert.h>

int recursive(int arr[], int x, int low, int high)
{
    const int mid = floor(low + (high - low) / 2);

    if (high >= low) {
        if (arr[mid] == x) {
            return mid;
        }

        if (x < arr[mid]) {
            return recursive(arr, x, low, mid - 1);
        } else {
            return recursive(arr, x, mid + 1, high);
        }
    }
    return -1;
}

int iterative(int arr[], int x, int low, int high)
{
    while (low <= high)
    {
        const int mid = floor(low + (high - low) / 2);
        if (arr[mid] == x) {
            return mid;
        }

        if (x < arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int length = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < length; i++)
    {
        assert(iterative(arr, 3, 0, length - 1) == 2);
        assert(recursive(arr, 11, 0, length - 1) == -1);
        assert(iterative(arr, 3, 0, length - 1) == 2);
        assert(recursive(arr, 11, 0, length - 1) == -1);
    }


    return 0;
}
