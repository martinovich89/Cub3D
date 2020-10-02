#include "libft.h"

int is_in_str(char *line, char c)
{
    while (*line)
    {
        if (*line == c)
            return (1);
        line++;
    }
    return (0);
}