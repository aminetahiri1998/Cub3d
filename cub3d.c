/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 09:07:34 by atahiri           #+#    #+#             */
/*   Updated: 2020/03/05 13:26:56 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    initialize_player()
{
    
    g_player->x = 60;
    g_player->y = 60;
    g_player->turn_d = 0;
    g_player->walk_d = 0;
    g_player->angle = (30 * RAD);
    g_player->turn_spd = 10 * RAD;
    g_player->walk_spd = 5;
    
}

int		main(/*int argc, char **argv*/)
{
    

	// if (argc != 2)
        // {
        // 	write(1, "Error in arguments...", 22);
        // 	return (0);
        // }
        // if (handle_argv(argv[1]) == 2)
        // {
        // 	write(1, "Invalid / not found Map File ...", 32);
        // 	return(0);
        // }
        //handle(argv[1], &data.parse, &data);
        //ft_init(&data);
    if (!(g_data = ((t_struct*)malloc(sizeof(t_struct)))))
        return (0);
    if (!(g_player = (t_player*)malloc(sizeof(t_player))))
        return (0);
    initialize_player();
    g_data->ptr = mlx_init();
	g_data->win = mlx_new_window(g_data->ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3d");
    g_data->image = mlx_new_image(g_data->ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
    //g_data->matrix = (int*)mlx_get_data_addr(g_data->image, &g_data->bits_per_pixel, &g_data->size_line, &g_data->endian);
    mlx_hook(g_data->win, 2, 0, keypress, g_player);
    mlx_hook(g_data->win, 3, 0, keyrelease, g_data);
    mlx_loop_hook(g_data->ptr, loop, g_data);
    mlx_loop(g_data->ptr);
	return (0);
}