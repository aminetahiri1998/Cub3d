/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:58:40 by atahiri           #+#    #+#             */
/*   Updated: 2020/03/09 22:07:02 by atahiri          ###   ########.fr       */
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
		threed.cor_distance = g_ray[i].distance *
		cosf(g_ray[i].ray_angle - g_player->angle);
		threed.dis_proj_pln = (WINDOW_WIDTH / 2) / tanf(FOV_ANGLE / 2);
		threed.prj_wall_h = (TILE_SIZE / (threed.cor_distance == 0 ? 0.1 :
		threed.cor_distance)) * threed.dis_proj_pln;
		threed.wall_tp_px = (WINDOW_HEIGHT / 2) - (threed.prj_wall_h / 2);
		threed.wall_tp_px = threed.wall_tp_px < 0 ? 0 : threed.wall_tp_px;
		threed.wall_bottom_px = (WINDOW_HEIGHT / 2) + (threed.prj_wall_h / 2);
		threed.wall_bottom_px = threed.wall_bottom_px > WINDOW_HEIGHT ?
		WINDOW_HEIGHT : threed.wall_bottom_px;
		while (j < threed.wall_tp_px)
			g_data->matrix3d[(WINDOW_WIDTH * j++) + i] = 0xc4d8e2;
		while (j < threed.wall_bottom_px)
			g_data->matrix3d[(WINDOW_WIDTH * j++) + i] = g_ray[i].hit_ver ? 0xcb4154 : 0xfffff;
		while (j < WINDOW_HEIGHT)
			g_data->matrix3d[(WINDOW_WIDTH * j++) + i] = 0x8b5a2b;
		i++;
	}
}
