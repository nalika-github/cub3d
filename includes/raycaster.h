/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:09:08 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/24 13:07:48 by marvin           ###   ########.fr       */
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

# include "mlx.h"
# include "libft.h"
# include "game_setup.h"
# include "get_next_line.h"

# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 800
# define PI 3.141592654
# define N_RAY 10


//init_main_struc.c

void	init_main_struc(t_main *main_struc);
void	*init_player(t_main *main_struc);

//init_ray_data.c

void	*init_ray(t_main *main_struc);
void	get_step_ray_dist(t_ray *ray);
void	get_first_step_ray_dist(t_ray *ray, t_player *p);
void	perform_dda(t_ray *ray, int **map, t_player *p);
void	cal_ray_projection_dist_n_wall_hight(t_ray *ray);

//bresenham.c

void	bresenham_x(t_image *img, int *x, int *y, int color);
void	imgpixelput(t_image *img, int x, int y, int color);
void	bresenham_y(t_image *img, int *x, int *y, int color);
void	drawline(t_image *img, int *x, int *y, int color);

#endif

