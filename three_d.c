/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:58:40 by atahiri           #+#    #+#             */
/*   Updated: 2020/03/05 18:20:40 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    three_d()
{
    int	i;
	int	j;

	i = 0;
    while (i < NUM_RAYS)
	{
		j = 0;
		float	cor_distance = g_ray[i].distance * cosf(g_ray[i].ray_angle - g_player->angle);
		float	distance_proj_plane = ((float)WINDOW_WIDTH / 2) / tanf(FOV_ANGLE / 2);
		float	project_wall_height = (float)(TILE_SIZE / cor_distance) * distance_proj_plane;
		//int		wall_stripe_height = (int)project_wall_height;
		float		wall_top_pixel = (WINDOW_HEIGHT / 2) - (project_wall_height / 2);
		wall_top_pixel = wall_top_pixel < 0 ? 0 : wall_top_pixel;
		
		float		wall_bottom_pixel = (WINDOW_HEIGHT / 2) + (project_wall_height / 2);
		wall_bottom_pixel = wall_bottom_pixel > WINDOW_HEIGHT ? WINDOW_HEIGHT : wall_bottom_pixel;
		while (j < wall_top_pixel)
		{
			g_data->matrix3d[(WINDOW_WIDTH * j) + i] = 0xFF3333;
			j++;
		}
		while (j < wall_bottom_pixel)
		{
			g_data->matrix3d[(WINDOW_WIDTH * j) + i] = 0xfff700;
			j++;
		}
		while (j < WINDOW_HEIGHT)
		{
			g_data->matrix3d[(WINDOW_WIDTH * j) + i] = 0x677687;
			j++;
		}
		i++;
	}
}

//(cor_distance == 0 ? 0.1f : cor_distance)