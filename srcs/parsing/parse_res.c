#include "cub.h"

void	set_res_h(t_env *env, int nb)
{
	if (nb > MAX_RES_H)
		env->conf->res_h = MAX_RES_H;
	if ((nb <= MAX_RES_H) && nb >= 300)
		env->conf->res_h = nb;
}

void	set_res_w(t_env *env, int nb)
{
	if (nb > MAX_RES_W)
		env->conf->res_w = MAX_RES_W;
	if ((nb <= MAX_RES_W) && nb >= 300)
		env->conf->res_w = nb;
}

void	parse_res(t_env *env, char *line)
{
	char	**tab;

	if (!(tab = ft_split(line, ' ')))
		ft_error("ram allocation error\n", env);
	if (ft_tablen(tab) != 3 || ft_atoi(tab[1]) < 300 || ft_atoi(tab[2]) < 300)
	{
		ft_tabdel(tab);
		ft_error("invalid res line\n", env);
	}
	set_res_w(env, ft_atoi(tab[1]));
	set_res_h(env, ft_atoi(tab[2]));
	if (tab)
		ft_tabdel(tab);
}