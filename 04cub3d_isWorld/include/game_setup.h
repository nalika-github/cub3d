/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:31:21 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/14 23:29:04 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_SETUP_H
# define GAME_SETUP_H

# include "../libft/libft.h"
# include <stdbool.h>

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_coor //coordinate
{
	double	x;
	double	y;
}	t_coor;

typedef struct s_ray
{
	t_coor	raydir; //ray coordinate on camera plane
	double	rdx; //initial step x ray distance + total step rdx
	double	rdy; //initial step y ray distance + total step rdy
	double	step_rdx; //step x ray distance
	double	step_rdy; //step y ray distance
	double	lcpd; //local_cam_plane_dist
	int		step_side_x; // the indicator to define step in x direction
	int		step_side_y; // the indicator to define step in y direction
	bool	wall_hit_side; // if hit N or S wall_hit_side = 0, if hit E or W wall_hit_side = 1
	double	proj_dist; // project distance from camera
	int		wall_hight; // wall hight distance
	int		wall_y_start; // start from top
	int		wall_y_end; // end at bottom
	int		wall_x_start; // start from left
	int		wall_x_end; // end at right
	int		index;
}	t_ray;

typedef struct s_imgdata
{
	void	*img;
	char	*addr;
	int		bpp;
	int		llen;
	int		endian;
}	t_imgdata;

typedef struct s_map
{
	t_list	*iden; //
	bool	map_begin; //
	int		line_map_begin; //
	char	**map_original; //
	int		mapx; //
	int		mapy; //
	int 	maps; //
	int		**map; //
}	t_map;

typedef struct s_player
{
	int		map_x; //x position in map //
	int		map_y; //y position in map //
	t_coor	*pos; //position of player in coordinate system //
	t_coor	dir; //direction of player //
	t_coor	cam_plane; //the coordinate of the center of the camera plane //
	bool	one_player; //
	char	D; //
	int		psize; //
}	t_player;

typedef struct s_frame
{
	int				w;//width
	int				h;//height
	unsigned int	bgc; //backgound color
	t_player		*p;//player position //
	t_map			*map; //
}	t_frame; 

typedef struct s_viewport /*t_mlx -> t_vp*/
{
	void		*mlx; //mlx_init()
	void		*win; //mlx_new_window()
	t_imgdata	*bgimg;  //
	t_imgdata	*mini_img; //
	t_frame 	*scene; //
}	t_vp;

typedef struct s_main
{
	t_vp 		*viewport; //
	t_map		*map;
	t_player	*player; 
	t_ray		*ray;
	int			wall_strip_width; 
	double		cur_time;
	double		old_time;
}	t_main;	

// typedef struct s_main
// {
// 	t_vp		viewport;
// 	t_image		mini_map; //->viewport.mini_img // unused
// 	int			**map; //->map->map
// 	int			wall_strip_width;
// 	t_player	*player;
// 	t_ray		*ray;
// 	double		cur_time;
// 	double		old_time;
// 	bool		one_player; //->player->one_player
// 	int			ms; //->player->ms
// }	t_main;

#endif
