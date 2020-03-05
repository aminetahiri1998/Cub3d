/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 11:25:22 by atahiri           #+#    #+#             */
/*   Updated: 2020/03/05 13:26:47 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float     distance_between_points(float x1, float y1, float x2, float y2)
{
    return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

float    normalize_angle(float angle)
{
    if (angle <= 0)
        angle += (2 * M_PI);
    else if (angle >= (2 * M_PI))
        angle -= (2 * M_PI);
    return(angle);
}

void    draw_single_ray(int strip_id)
{
    float   x;
    float   y;
    int     i;
    i = 0;
    x = g_player->x;
    y = g_player->y;
    while (i <= g_ray[strip_id].distance)
    {
        mlx_pixel_put(g_data->ptr, g_data->win, x, y, 0xE84118);
        x += cosf(g_ray[strip_id].ray_angle);
        y += sinf(g_ray[strip_id].ray_angle);
        i++;
    }
}

void    cast_rays()
{
    int     strip_id;
    float   ray_angle;

    strip_id = 0;
    ray_angle = g_player->angle - (float)(FOV_ANGLE / 2);
    while (strip_id < NUM_RAYS)
    {
        g_ray[strip_id].ray_angle = normalize_angle(ray_angle);
        handle_rays(strip_id);
        draw_single_ray(strip_id);
        ray_angle += FOV_ANGLE / NUM_RAYS;
        strip_id++;
    }
}