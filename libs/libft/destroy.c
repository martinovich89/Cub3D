#include "libft.h"

void    destroy(void **ptr)
{
    if (ptr)
    {
        free(ptr);
        ptr = NULL;
    }
}