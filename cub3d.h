/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 09:09:05 by atahiri           #+#    #+#             */
/*   Updated: 2020/03/13 23:17:11 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <stdint.h>

# define ESC 53
# define LEFT 0
# define RIGHT 2
# define FORWARD 13
# define BACKWARD 1
# define KEYUP 3
# define KEYDOWN 2
# define QUIT 17 

# define TILE_SIZE 400
# define RAD (M_PI / 180)
# define MAP_NUM_ROWS 14
# define MAP_NUM_COLS 29
# define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
# define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)
# define WINDOW_WIDTH_D 1600
# define WINDOW_HEIGHT_D 900
# define FOV_ANGLE (60 * RAD)
# define WALL_STRIP_WIDTH 1
# define NUM_RAYS WINDOW_WIDTH_D
# define INT_MAXX 2147483647



typedef struct s_ray
{
    float		ray_angle;
	float		wall_hit_x;
	float		wall_hit_y;
	float		distance;
	int			hit_ver;
	int			wall_facing_up;
	int			wall_facing_down;
	int			wall_facing_left;
	int			wall_facing_right;
	int			wall_hit_content;
}				t_ray;

typedef struct s_player
{
    float x;
    float y;
    int turn_d; // -1 for left , +1 for right
    int walk_d; // -1 for back , +1 for front
    float angle;
    float walk_spd;
    float turn_spd;
}               t_player;

typedef struct	s_struct
{
	void	*ptr;
	void	*win;
	void	*image;
	void	*image3d;
	int		*matrix;
	int		*matrix3d;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_struct;

typedef struct s_texture
{
	void 	*img;
    int 	width;
    int 	height;
	char	*path;
	int		*color;
}			t_texture;

typedef	struct s_three_d
{
	float	cor_distance;
	float	dis_proj_pln;
	float	prj_wall_h;
	float	wall_tp_px;
	float	wall_bottom_px;
}				t_three_d;


t_struct	*g_data;
t_player	*g_player;
t_ray		g_ray[NUM_RAYS];
t_three_d	threed;
t_texture	texture[4];


int     check_folder(char *str);
int     handle_argv(char *str);
int     ft_strlen(char *str);
int		ft_memcmp_zero(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int     keyrelease(int keycode);
int     keypress(int keycode);
void    initialize_player();
void    draw_map();
void    draw_squar(int x, int y, int color);
void	three_d(void);
int		loop();
void    move_player();
void	draw_player();
int		wall_check(float x, float y);
void    draw_single_ray(int strip_id);
void    cast_rays(void);
void    handle_rays(int strip_id);
float	distance_between_points(float x1, float y1, float x2, float y2);
float	normalize_angle(float angle);
void    handling_textures();

#endif