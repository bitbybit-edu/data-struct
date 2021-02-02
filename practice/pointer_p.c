#include <stdio.h>

int main()
{
    int var = 20;
    int *ip;
    ip = &var;

    printf("var 变量的地址: %p\n", &var);

    /* 在指针变量中存储的地址 */
    printf("ip 变量存储的地址: %p\n", ip);

    /* 使用指针访问值 */
    printf("ip 变量的值: %p \n", *ip);
}