#include "guindows.h"
#include <stdio.h>

static task t1, t2, t3, taskmain;

static void ft1(void)
{
    int a = 1;
    printf("%p\n", &a);
    for (double d = -1; ; d += 0.001) {
        printf("d=%f\n", d);
        TRANSFER(t1, t2);
    }
}

static void ft2(void)
{
    int a = 1;
    printf("%p\n", &a);
    for (unsigned i = 0; i < 10000; i++) {
        printf("i=%u\n", i);
        TRANSFER(t2, t3);
    }
}

void ft3(void)
{
    int a = 1;
    printf("%p\n", &a);
    for (unsigned i = 0; i < 5000; i++) {
        printf("t3: i=%u\n", i);
        TRANSFER(t3, t1);
    }
    TRANSFER(t3, taskmain);
}

int main(void)
{
    stack(t1, ft1);
    stack(t2, ft2);
    stack(t3, ft3);
    TRANSFER(taskmain, t1);
    return 0;
}
