#include "cub.h"

void    ft_error(char *str, t_env *env)
{
	ft_clear_env(env);
    ft_putstr(str);
    exit(1);
}
