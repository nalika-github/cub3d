/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:09:08 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/13 21:21:37 by pnopjira         ###   ########.fr       */
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
# include <OpenGL/gl3.h>
# include "../mlx/mlx.h"
# include "get_next_line.h"
# include "../libft/libft.h"
# include "game_setup.h"

# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define RESET "\033[0m"
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_A_LEFT 0
# define KEY_S_DOWN 1
# define KEY_D_RIGHT 2
# define KEY_W_UP 13
# define RATIO_RPC 10 //ration ระหว่างตัวขนาดห้องต่อตัวละคร

/*cub3d*/
int		check_invalid_filedata(char *maps_path, t_map **map, t_pos **p);
int     raycaster(t_var *vars);

/*pnopjira_utils*/
//00map_setup
int		rd_mapdata(char *maps_path, t_map **map, t_pos **p);
void    iden_list(t_list **iden);
void	init_plan(t_map *plan);
void	init_player(t_pos *player);
void	init_map(t_frame *scene);
//01map_setup
void	del_nl(char **line);
int		setup_pos(char *dir,int x, int y, t_pos **p);
int		setup_pos_mapx(char **mapdata, int j, t_map **map, t_pos **p);
void	before_map_line(int fd2, int map_begin, char **line);
void	ck_invalid_map(int *err, int fd2, t_map **map, t_pos **p);
//02map_setup
void	print_map_original(char **map_original, t_map **map, t_pos **p);
int		mapsize(t_map *m, t_pos *p);
void	key_to_content(void **iden, char *key, char *content);
//03map_setup
int		char_to_int_map(char **o_map, t_map **plan);
int		ck_map_info(t_map **map);
void	print_new_map(int ***map, int j, int i); //for test
//check_dataformat
int		init_content(t_list **iden, char **dst, char **src, char *key);
int		ck_no_so_we_ea(char *tmp, t_list **iden);
int		ck_f_c_color(char *tmp, t_list **iden);
void	ck_data_format(char *tmp, int *err, t_map **map);
void	ck_invalid_data(int *err, int fd1, t_map **map);
//check_invalid
int		explicit_error(int stage);
int		invalid_filepath(char *maps_path, char *path, char *format);
int		invalid_color_code(char *rgb);
int		ck_identify(int *err, t_list *iden);
int		before_map(t_map **map, int *err);

//free_allocated
void	del(void *lst);
void	free_scene(t_frame **scene);
int		free_on_exit(t_var *vars);
//get_next_line
char	*get_next_line(int fd);
//frame_setup
int		init_frame(t_frame *scene);
int		set_player(t_pos *p, t_map *m);

/*ptungbun_utils*/

//init_main_struc.c

void	init_main_struc(t_main *main_struc);
void	*init_player(t_main *main_struc);

//init_ray_data.c

void	*init_ray(t_main *main_struc);
void	get_step_ray_dist(t_ray *ray);
void	get_first_step_ray_dist(t_ray *ray, t_player *p);
void	perform_dda(t_ray *ray, t_map **map, t_player *p);
void	cal_ray_projection_dist_n_wall_hight(t_ray *ray);

//bresenham.c

void	bresenham_x(t_image *img, int *x, int *y, int color);
void	imgpixelput(t_image *img, int x, int y, int color);
void	bresenham_y(t_image *img, int *x, int *y, int color);
void	drawline(t_image *img, int *x, int *y, int color)

#endif

