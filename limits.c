#include <stdio.h>
#include <limits.h>

void limitChar(void)
{
    printf("char �洢��С : %lu \n", sizeof(char));
}

void main()
{
    printf("int �洢��С : %lu \n", sizeof(int));
    printf("\a");
    limitChar();
}

