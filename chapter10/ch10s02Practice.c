// http://docs.linuxtone.org/ebooks/C&CPP/c/ch10s02.html
#include <stdio.h>

int main(void)
{
    int i;
    char str[6] = "hello";
    char reverse_str[6] = "";
    printf("%s\n", str);
    for (i = 0; i < 5; i++)
        reverse_str[4 - i] = str[i];
    reverse_str[5] = '\0';
    printf("%s\n", reverse_str);
    return 0;
}