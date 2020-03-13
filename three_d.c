/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:58:40 by atahiri           #+#    #+#             */
/*   Updated: 2020/03/13 18:37:49 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	three_d(void)
{
	int			i;
	int			j;

	i = 0;
	while (i < NUM_RAYS)
	{
		j = 0;
		threed.cor_distance = g_ray[i].distance * cosf(g_ray[i].ray_angle - g_player->angle);
		threed.dis_proj_pln = (WINDOW_WIDTH_D / 2) / tanf(FOV_ANGLE / 2);
		threed.prj_wall_h = (TILE_SIZE / (threed.cor_distance == 0 ? 0.1 : threed.cor_distance)) * threed.dis_proj_pln;
		threed.wall_tp_px = (WINDOW_HEIGHT_D / 2) - (threed.prj_wall_h / 2);
		threed.wall_tp_px = threed.wall_tp_px < 0 ? 0 : threed.wall_tp_px;
		threed.wall_bottom_px = (WINDOW_HEIGHT_D / 2) + (threed.prj_wall_h / 2);
		threed.wall_bottom_px = threed.wall_bottom_px > WINDOW_HEIGHT_D ? WINDOW_HEIGHT_D : threed.wall_bottom_px;
		while (j < threed.wall_tp_px)
			g_data->matrix3d[(WINDOW_WIDTH_D * j++) + i] = 0xc4d8e2;
		int textureOffsetX;
        if (g_ray[i].hit_ver)
            textureOffsetX = (int)g_ray[i].wall_hit_y % TILE_SIZE;
        else
            textureOffsetX = (int)g_ray[i].wall_hit_x % TILE_SIZE;
		textureOffsetX = textureOffsetX >= TILE_SIZE ? TILE_SIZE - 1 : textureOffsetX;
        while (j < threed.wall_bottom_px) 
		{
            float distanceFromTop = (float)j + (threed.prj_wall_h  / 2.0F) - ((float)WINDOW_HEIGHT_D / 2.0F);
            int textureOffsetY = distanceFromTop * ((float)TILE_SIZE / threed.prj_wall_h);
			textureOffsetY = textureOffsetY >= TILE_SIZE ? TILE_SIZE-1 : textureOffsetY;
            int texelColor = texture[0].color[(TILE_SIZE * textureOffsetY) + textureOffsetX];
            g_data->matrix3d[(WINDOW_WIDTH_D * j++) + i] = texelColor;
        }
		while (j < WINDOW_HEIGHT_D)
			g_data->matrix3d[(WINDOW_WIDTH_D * j++) + i] = 0x8b5a2b;
		i++;
	}
}