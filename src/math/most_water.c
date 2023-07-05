#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * https://leetcode.com/problems/container-with-most-water/description/
 */
int max_area(int height[], int heightSize) {
    if (heightSize == 0) {
        return 0;
    }
    int left = 0;
    int right = heightSize - 1;

    int max = 0;
    while (left < right) {
        const int h =
            height[left] <= height[right] ? height[left] : height[right];
        const int area = h * (right - left);
        if (max < area) {
            max = area;
        }
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return max;
}

int main(int argc, char const *argv[]) {
    {
        int array[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        assert(max_area(array, sizeof(array) / sizeof(array[0])) == 49);
    };
    {
        int array[] = {1, 1};
        assert(max_area(array, sizeof(array) / sizeof(array[0])) == 1);
    };
    {
        int array[] = {2, 1};
        assert(max_area(array, sizeof(array) / sizeof(array[0])) == 1);
    };
    {
        int array[] = {2, 3, 4, 5, 18, 17, 6};
        assert(max_area(array, sizeof(array) / sizeof(array[0])) == 17);
    };

    return 0;
};
