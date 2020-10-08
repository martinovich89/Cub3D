#include "cub.h"
#include <math.h>

int     pos;
int     dir;
int     plane;

void    init_dir(t_cub *cub)
{
    if (cub->conf->dir = 'N')
    {
        cub->map->dir->x = -1.0F;
        cub->map->dir->y = 0.0F;
    }
    if(cub->conf->dir = 'E')
    {
        cub->map->dir->x = 0.0F;
        cub->map->dir->y = 1.0F;
    }
    if (cub->conf->dir = 'W')
    {
        cub->map->dir->x = 0.0F;
        cub->map->dir->y = -1.0F;
    }
    if (cub->conf->dir = 'S')
    {
        cub->map->dir->x = 1.0F;
        cub->map->dir->y = 0.0F;
    }
}

void    init_pos(t_cub *cub)
{
    int i;
    int j;

    i = 0;
    while (cub->conf->map[i])
    {
        j = 0;
        while (cub->conf->map[i][j])
        {
            if (is_in_str("NEWS", cub->conf->map[i][j]))
            {
                cub->map->pos->x = (float)j;
                cub->map->pos->y = (float)i;
            }
            j++;
        }
        i++;
    }
}

float    rad_conv(float angle)
{
    float ret;
    ret = angle * M_PI / 180;
    return (ret);
}

void    init_fov(t_cub* cub)
{
    cub->map->fov = rad_conv(FOV);
}

void    init_plane(t_cub *cub)
{
    cub->map->plane->x = plane_calc(cub->map->dir, cub->map->plane, cub->map->fov);
}

void    cam_calc(t_cub *cub, int nb)
{
    cub->map->cam_ratio = ((float)nb / ((float)cub->conf->res_w / 2.0F)) - 1.0F;
}

void    ray_calc(t_cub *cub)
{
    cub->map->ray->x = cub->map->dir->x + cub->map->plane->x * cub->map->cam_ratio;
    cub->map->ray->y = cub->map->dir->y + cub->map->plane->y * cub->map->cam_ratio;
}

void    gab_calc(t_cub *cub)
{
    if (cub->map->ray->y == 0.0F)
        cub->map->gapX = 0.0F;
    else
    {
        cub->map->gapX = (cub->map->ray->x == 0.0F) ? 1.0F : abs(1.0F / cub->map->ray->x);
    }
    if (cub->map->ray->x == 0.0F)
        cub->map->gapY = 0.0F;
    else
    {
        cub->map->gapY = (cub->map->ray->y == 0.0F) ? 1.0F : abs(1.0F / cub->map->ray->y);
    }
}

void    mapXY_calc(t_map *map)
{
    map->x = (int)map->pos->x;
    map->y = (int)map->pos->y;
}

void    sign_calc(t_map *map)
{
    map->signX = (map->dir->x < 0.0F) ? -1 : 1;
    map->signY = (map->dir->y < 0.0F) ? -1 : 1;
}

void    next_calc(t_cub *cub)
{
    cub->map->gapX = (cub->map->ray->x < 0.0F)
    ? (cub->map->pos->x - (float)cub->map->x) * cub->map->gapX
    : ((float)cub->map->x + 1.0F - cub->map->pos->x) * cub->map->gapX;
    cub->map->gapY = (cub->map->ray->y < 0.0F)
    ? (cub->map->pos->y - (float)cub->map->y) * cub->map->gapY
    : ((float)cub->map->y + 1.00F - cub->map->pos->y) * cub->map->gapY;
}

void    wall_dist_calc(t_cub *cub)
{
    int mapX;
    int mapY;

    mapX = cub->map->x;
    mapY = cub->map->y;
    while (cub->conf->map[mapX][mapY] != 1)
    {
        if(cub->map->nextX < cub->map->nextY)
        {
            cub->map->nextX += cub->map->gapX;
            mapX += cub->map->signX;
            cub->map->side = (cub->map->dir->x < 0.0F) ? 0 : 3;
        }
        else
        {
            cub->map->nextY += cub->map->gapY;
            mapY += cub->map->signY;
            cub->map->side = (cub->map->dir->y < 0.0F) ? 2 : 1;
        }
        
    }
}

void    perp_wall_dist_calc(t_map *map)
{
    if (map->side == 0 || map->side == 3)
        map->perp_wall_dist = ((float)map->x - map->pos->x
        + (1.0F - (float)map->signX) / 2.0F) / map->ray->x;
    else
        map->perp_wall_dist = ((float)map->y - map->pos->y
        + (1.0F - (float)map->signY) / 2.0F) / map->ray->y;
}

void    wall_calc(t_cub *cub)
{
    cub->rndr->wallH
    = (int)((float)cub->conf->res_h / cub->map->perp_wall_dist);
    cub->rndr->wall_top
    = (int)(((float)cub->conf->res_h - (float)cub->rndr->wallH) / 2.0F);
    cub->rndr->wall_bot
    = (int)((float)cub->conf->res_h / 2.0F + (float)cub->rndr->wallH / 2.0F); // -hmur/2 + hmur = hmur/2
    if (cub->rndr->wall_top < 0)
        cub->rndr->wall_top = 0;
    if (cub->rndr->wall_top >= cub->conf->res_h)
        cub->rndr->wall_top = cub->conf->res_h - 1;
}

void    ratio_calc(t_cub *cub)
{
    cub->rndr->ratio = (float)cub->rndr->wallH / (float)cub->conf->res_h;
}

void    wallX_calc(t_cub *cub)
{
    if (cub->map->side == 0 || cub->map->side == 3)
        cub->rndr->wallX = cub->map->pos->y + cub->map->perp_wall_dist * cub->map->ray->y;
    else
        cub->rndr->wallX = cub->map->pos->x + cub->map->perp_wall_dist * cub->map->ray->x;
    if (cub->map->side == 0 || cub->map->side == 2)
        cub->rndr->wallX = (float)cub->map->x + 1.0F - cub->rndr->wallX;
    else
        cub->rndr->wallX = cub->rndr->wallX - (float)cub->map->x;
    
}

void    texPos_calc(t_cub *cub)
{
    cub->rndr->texPos
    = (((float)cub->rndr->wallH - (float)cub->conf->res_h) / 2.0F
    + (float)cub->rndr->wall_top) * cub->rndr->ratio;
}

void    texXY_calc(t_cub *cub)
{
    cub->rndr->texX = (int)(cub->rndr->wallX * (float)cub->rndr->texW);
    cub->rndr->texY = (int)cub->rndr->texPos;
}

void    fill_stripe(t_cub *cub, int i)
{
    int j;

    j = 0;
    while (j < cub->conf->res_h && j < cub->rndr->wall_top)
    {
        cub->rndr->img[i][j] = (unsigned int)cub->conf->ceil;
        j++;
    }
    while (j >= cub->rndr->wall_top && j <= cub->rndr->wall_bot)
    {
        cub->rndr->img[i][j] = (tex[cub->map->side][cub->rndr->texX][cub->rndr->texY]);
        cub->rndr->texPos += cub->rndr->ratio;
        cub->rndr->texY = (int)cub->rndr->texPos & (cub->rndr->texH - 1);
        j++;
    }
    while (j < cub->conf->res_h)
    {
        cub->rndr->img[i][j] = (unsigned int)cub->conf->floo;
        j++;
    }
}

void    ray_casting(t_cub *cub)
{
    int i;

    ft_build_uint_tab(cub->conf->res_w, cub->conf->res_h);
    i = 0;
    while (i < cub->conf->res_w)
    {
        cam_calc(cub, i);
        ray_calc(cub);
        gap_calc(cub);
        mapXY_calc(cub->map);
        sign_calc(cub->map);
        next_calc(cub);
        wall_dist_calc(cub);
        perp_wall_dist_calc(cub->map);
        wall_calc(cub);
        ratio_calc(cub);
        wallX_calc(cub);
        texPos_calc(cub);
        texXY_calc(cub);
        fill_stripe(cub, i);
        i++;
    }
}