#include <stdlib.h>
#include <stdio.h>

typedef struct  s_test
{
    int x;
    int y;
}               t_test;

void            ft_test(t_test **test)
{
    int a;
    int b;

    a = (*test)->x;
    b = (*test)->y;
    printf("%d%d", a, b);
}

int             main(void)
{
    t_test *test;

    test = malloc(sizeof(t_test));
    test->x = 0;
    test->y = 1;
    ft_test(&test);
}