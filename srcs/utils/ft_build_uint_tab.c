#include "cub.h"

unsigned int    **ft_build_uint_tab(int w, int h)
{
    unsigned int    **tab;
    int             i;

    i = 0;
    if (!(tab = malloc(sizeof(*tab) * h)))
        return (NULL);
    while (i < h)
    {
        if (!(tab[i] = malloc(sizeof(**tab) * w)))
            return (NULL);
        i++;
    }
    return (tab);
}