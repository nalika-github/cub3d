/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:09:08 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/13 20:35:27 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>

# include <mlx.h>
# include "libft.h"
# include "game_setup.h"
# include "get_next_line.h"

# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 800
# define PI 3.141592654
# define N_RAY 300
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307
# define MOVE_SPEED 0.02

//init_main_struc.c

void	init_main_struc(t_main *main_struc);
void	*init_player(t_main *main_struc);
void	init_viewport(t_main *main_struc);

//init_ray_data.c

void	*init_ray(t_main *main_struc);
void	get_step_ray_dist_n_ray_width(int wall_strip_width, t_ray *ray, int is_init);
void	get_first_step_ray_dist(t_ray *ray, t_player *p);
void	perform_dda(t_ray *ray, int **map, t_player *p);
void	cal_ray_projection_dist_n_wall_hight(t_ray *ray);

//bresenham.c

void	bresenham_x(t_image *img, int *x, int *y, int color);
void	imgpixelput(t_image *img, int x, int y, int color);
void	bresenham_y(t_image *img, int *x, int *y, int color);
void	drawline(t_image *img, int *x, int *y, int color);

//cub3d_render.c

void	cub3d_render(t_main *main_struc, t_vp *vp);

//move_even.c

int		move_even(int key, t_main *main_struc);
void	move_forward_or_back(t_main *m, int key);
void	turn_left_or_right(t_main *m, int key);
int		is_wall_block(t_main *m, int index);

//exit_even.c

int	exit_even(int key, t_main *main_struc);
int	end_programe(t_main *main_struc);

//rotate.c

void	rotate(t_main *main_struc, double degree);

#endif

