#include <assert.h>

void product_except_self(int nums[], int length, int output[]) {
    for (int i = 0; i < length; i++) {
        int product = 1;
        for (int j = 0; j < length; j++) {
            if (i == j)
                continue;
            product *= nums[j];
        }
        output[i] = product;
    }
}

int main(int argc, char const *argv[]) {
    {
        int nums[4] = {1, 2, 3, 4};
        int output[4] = {};
        product_except_self(nums, 4, output);
        assert(output[0] == 24 && output[1] == 12 && output[2] == 8 &&
               output[3] == 6);
    }
    {
        int nums[5] = {-1, 1, 0, -3, 3};
        int output[5] = {};
        product_except_self(nums, 5, output);
        assert(output[0] == 0 && output[1] == 0 && output[2] == 9 &&
               output[3] == 0 && output[4] == 0);
    }
    return 0;
};
