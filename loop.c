/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 23:26:13 by atahiri           #+#    #+#             */
/*   Updated: 2020/03/05 13:48:42 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int loop()
{
    //mlx_clear_window(g_data->ptr, g_data->win);
    draw_map();
    move_player();
    cast_rays();
    //mlx_put_image_to_window(g_data->ptr, g_data->win, g_data->image, 0, 0);
    return (0);
}