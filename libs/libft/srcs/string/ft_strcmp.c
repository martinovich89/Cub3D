#include "libft.h"

int     ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

    ptr1 = (unsigned char *)s1;
    ptr2 = (unsigned char *)s2;
    while (*ptr1 && *ptr1 == *ptr2)
    {
        ptr1++;
        ptr2++;
    }
    return (*ptr1 - *ptr2);
}