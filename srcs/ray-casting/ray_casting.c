#include "cub.h"

void	map_all_calc(t_env *env, int i)
{
	plane_calc(env->map->dir, &env->map->plane, -env->map->fov);
	cam_calc(env, i);
	ray_calc(env);
	gap_calc(env);
	mapXY_calc(env->map);
	sign_calc(env->map);
	next_calc(env);
	wall_dist_calc(env, i);
	perp_wall_dist_calc(env->map);
	wall_calc(env);
	pick_texture(env);
	ratio_calc(env);
	wallX_calc(env);
	texPos_calc(env);
	texXY_calc(env);
}

void	apply_moves(t_env *env)
{
	int pwet;

	pwet = 0;
	(env->left == 1)
	? rotation(&env->map->dir, (env->map->fov / 50000 * -1)) : pwet--;
	(env->right == 1)
	? rotation(&env->map->dir, (env->map->fov / 50000)) : pwet--;
	(env->up == 1) ? translation(env, 0) : pwet++;
	(env->down == 1) ? translation(env, 2) : pwet--;
	(env->strafe_left == 1) ? translation(env, 3) : pwet--;
	(env->strafe_right == 1) ? translation(env, 1) : pwet--;
}

void	ray_casting(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->conf->res_w)
	{
		apply_moves(env);
		map_all_calc(env, i);
		fill_stripe(env, i);
		i++;
	}
}