#include<stdio.h>
#include<stdalign.h>
#include<stdbool.h>
#include<math.h>

bool is_prime(int n)
{
    if(n < 2)return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    const int value = sqrt(n);

    for (int i = 3; i <= value; i+=2)
    {
        if(n % i) return false;
    }
    return true;
}
int main(int argc, char const *argv[])
{
    const int nums[] = {0,1,2,3,4,5,6,7,8,9,10};
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
    {
        printf("%d: %d\n", nums[i], is_prime(nums[i]));
    }

    return 0;
}
