#include "cub.h"

void    ft_error(char *str, t_cub *cub)
{
	ft_clear_env(cub);
    ft_putstr(str);
    exit(1);
}
