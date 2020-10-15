#include "cub.h"

void	sign_calc(t_map *map)
{
	map->signX = (map->ray.x < 0.0F) ? -1 : 1;
	map->signY = (map->ray.y < 0.0F) ? -1 : 1;
}

void	next_calc(t_env *env)
{
	env->map->nextX = (env->map->ray.x < 0.0F)
	? (env->map->pos.x - (float)env->map->x) * env->map->gapX
	: ((float)env->map->x + 1.0F - env->map->pos.x) * env->map->gapX;
	env->map->nextY = (env->map->ray.y < 0.0F)
	? (env->map->pos.y - (float)env->map->y) * env->map->gapY
	: ((float)env->map->y + 1.00F - env->map->pos.y) * env->map->gapY;
}

void	wall_dist_calc(t_env *env, int i)
{
	while (env->conf->map[env->map->y][env->map->x] != '1')
	{
		if (env->map->nextX < env->map->nextY)
		{
			env->map->nextX += env->map->gapX;
			env->map->x += env->map->signX;
			env->map->side = (env->map->ray.x < 0.0F) ? 0 : 3;
			if (env->conf->map[env->map->y][env->map->x] == '2')
				sprite_calc(env, i);
		}
		else
		{
			env->map->nextY += env->map->gapY;
			env->map->y += env->map->signY;
			env->map->side = (env->map->ray.y < 0.0F) ? 2 : 1;
			if (env->conf->map[env->map->y][env->map->x] == '2')
				sprite_calc(env, i);
		}
	}
}

void	perp_wall_dist_calc(t_map *map)
{
	if (map->side == 0 || map->side == 3)
		map->perp_wall_dist = ((float)map->x
		- map->pos.x + (1.0F - (float)map->signX) / 2.0F) / map->ray.x;
	else
		map->perp_wall_dist = ((float)map->y - map->pos.y
		+ (1.0F - (float)map->signY) / 2.0F) / map->ray.y;
}

void	sprite_pos_calc(t_env *env)
{
	env->sp.pos.x = (float)env->map->x + 0.5F;
	env->sp.pos.y = (float)env->map->y + 0.5F;
}

void	perp_sprite_dist_calc(t_env *env)
{
	float	xR;
	float	yR;

	env->map->plane.posX = env->map->pos.x + env->map->dir.x;
	env->map->plane.posY = env->map->pos.y + env->map->dir.y;
	env->map->plane.coef = env->map->plane.y / env->map->plane.x;
	env->map->plane.intercept = env->map->plane.posY - env->map->plane.coef * env->map->plane.posX;
	env->sp.vector.posX = env->map->pos.x;
	env->sp.vector.posY = env->map->pos.y;
	env->sp.vector.coef = env->sp.vector.y / env->sp.vector.x;
	env->sp.vector.intercept = env->sp.vector.posY - env->sp.vector.coef * env->sp.vector.posX;
	xR = (env->map->plane.intercept - env->sp.vector.intercept) / (env->sp.vector.coef - env->map->plane.coef);
	yR = env->sp.vector.coef * xR + env->sp.vector.intercept;
	env->sp.pdist = env->sp.dist / sqrt(pow(xR - env->map->pos.x, 2) + pow(yR - env->map->pos.y, 2));
}

void	sprite_dist_calc(t_env *env)
{
	env->sp.vector.x = env->sp.pos.x - env->map->pos.x;
	env->sp.vector.y = env->sp.pos.y - env->map->pos.y;
	env->sp.dist = sqrtf(powf(env->sp.pos.x - env->map->pos.x, 2.0F)
	+ powf(env->sp.pos.y - env->map->pos.y, 2.0F));
	perp_sprite_dist_calc(env);
}

void	sprite_scaled_height_calc(t_env *env)
{
	env->sp.scaledH = (int)((float)env->conf->res_h / env->sp.pdist);
}

void	sprite_limits_calc(t_env *env)
{
	env->sp.top = (env->conf->res_h - env->sp.scaledH) / 2;
	if (env->sp.top < 0)
		env->sp.top = 0;
	env->sp.bot = (env->conf->res_h + env->sp.scaledH) / 2;
	if (env->sp.bot >= env->conf->res_h)
		env->sp.bot = env->conf->res_h - 1;
}

void	hit_line_calc(t_env *env)
{
	env->sp.hit_line.x = env->sp.vector.x;
	env->sp.hit_line.y = env->sp.vector.y;
	env->sp.hit_line.posX = env->map->pos.x + env->sp.vector.x;
	env->sp.hit_line.posY = env->map->pos.y + env->sp.vector.y;
	rotation(&env->sp.hit_line, (M_PI / 2));
	env->sp.hit_line.coef = env->sp.hit_line.y / env->sp.hit_line.x;
	env->sp.hit_line.intercept = env->sp.hit_line.posY - env->sp.hit_line.posX * env->sp.hit_line.coef;
}

void	intersection_calc(t_env *env)
{
	if ((env->map->ray.coef - env->sp.hit_line.coef) == 0.0001 && (env->map->ray.coef - env->sp.hit_line.coef) >= -0.0001)
	{
		env->sp.hit_posX = env->sp.pos.x;
		env->sp.hit_posY = env->sp.pos.y;
	}
	else if (env->sp.hit_line.coef <= 0.0001 && env->sp.hit_line.coef >= -0.0001)
	{
		env->sp.hit_posX = (env->sp.hit_line.intercept - env->map->ray.intercept) / (env->map->ray.coef - env->sp.hit_line.coef);
		env->sp.hit_posY = env->sp.pos.y;
	}
	else if (1 / env->sp.hit_line.coef <= 0.0001 && 1 / env->sp.hit_line.coef >= -0.0001)
	{
		env->sp.hit_posX = env->sp.pos.x;
		env->sp.hit_posY = env->map->ray.coef * env->sp.hit_posX + env->map->ray.intercept;
	}
	else
	{
		env->sp.hit_posX = (env->sp.hit_line.intercept - env->map->ray.intercept) / (env->map->ray.coef - env->sp.hit_line.coef);
		env->sp.hit_posY = env->map->ray.coef * env->sp.hit_posX + env->map->ray.intercept;
	}
}

void	set_hit(t_env *env)
{
	env->sp.hitX = sqrtf(powf((env->sp.hit_posX - env->sp.hit_line.posX), 2.0F) + powf((env->sp.hit_posY - env->sp.hit_line.posY), 2.0F));	
	env->map->inter.x = env->sp.hit_posX - env->map->pos.x;
	env->map->inter.y = env->sp.hit_posY - env->map->pos.y;
	if (env->sp.hitX <= 0.5)
	{
		env->sp.ok = 1;
		if (env->map->ray.y < 0 && fabs(env->map->ray.y) >= fabs(env->map->ray.x))
			env->sp.hitX = (env->map->inter.x > env->sp.vector.x) ? 0.5 + env->sp.hitX : 0.5 - env->sp.hitX;
		else if (env->map->ray.x > 0 && fabs(env->map->ray.x) >= fabs(env->map->ray.y))
			env->sp.hitX = (env->map->inter.y > env->sp.vector.y) ? 0.5 + env->sp.hitX : 0.5 - env->sp.hitX;
		else if (env->map->ray.y > 0 && fabs(env->map->ray.y) >= fabs(env->map->ray.x))
			env->sp.hitX = (env->map->inter.x < env->sp.vector.x) ? 0.5 + env->sp.hitX : 0.5 - env->sp.hitX;
		else if (env->map->ray.x < 0 && fabs(env->map->ray.x) >= fabs(env->map->ray.y))
			env->sp.hitX = (env->map->inter.y < env->sp.vector.y) ? 0.5 + env->sp.hitX : 0.5 - env->sp.hitX;
	}
	else
	{
		env->sp.ok = 0;
	}	
}

void	sprite_hit_calc(t_env *env)
{
	hit_line_calc(env);
	intersection_calc(env);
	set_hit(env);
}

void	sprite_ratio_calc(t_env *env)
{
	env->sp.ratio = (float)env->sp.tex.H / (float)env->sp.scaledH;
}

void	sprite_texPos_calc(t_env *env)
{
	env->sp.texPos = (((float)env->sp.scaledH - (float)env->conf->res_h) / 2.0F + (float)env->sp.top) * env->sp.ratio;
}

void	sprite_texXY_calc(t_env *env)
{
	env->sp.texX = (int)((float)env->sp.tex.W * env->sp.hitX);
	env->sp.texY = (int)env->sp.texPos;
}

void	sprite_calc(t_env *env, int i)
{
	sprite_pos_calc(env);
	sprite_dist_calc(env);
	sprite_scaled_height_calc(env);
	sprite_limits_calc(env);
	sprite_hit_calc(env);
	sprite_ratio_calc(env);
	sprite_texPos_calc(env);
	sprite_texXY_calc(env);
	if (env->sp.ok == 1)
		sprite_fill_stripe(env, i);
}