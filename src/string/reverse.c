#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverse(char *str)
{
    int length = strlen(str);
    for (int i = 0, j = length - 1; i < length / 2; i++, j--) {
        char value = str[i];
        str[i] = str[j];
        str[j] = value;
    }
}

int main(int argc, char const *argv[])
{
    char c1[] = "awesome";
    reverse(c1);
    printf("%s\n", c1);

    char c2[] = "rithmschool";
    reverse(c2);
    printf("%s\n", c2);
    return 0;
}
