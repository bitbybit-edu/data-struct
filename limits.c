#include <stdio.h>
#include <limits.h>

void limitChar(void)
{
    printf("char 存储大小 : %lu \n", sizeof(char));
}

void main()
{
    printf("int 存储大小 : %lu \n", sizeof(int));
    printf("\a");
    limitChar();
}

