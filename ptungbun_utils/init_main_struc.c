/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main_struc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:05:31 by ptungbun          #+#    #+#             */
/*   Updated: 2024/01/14 09:56:25 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycaster.h"
#include "../includes/game_setup.h"
#include "../includes/cub3d.h"


void	init_main_struc(t_main *main_struc)
{
	main_struc->cur_time = 0;
	main_struc->old_time = 0;
	main_struc->one_player = 0;
	init_viewport(main_struc);
	main_struc->wall_strip_width = \
	main_struc->viewport.img.line_len / (N_RAY - 1);
	init_player(main_struc);
	init_ray(main_struc);
}

void	init_viewport(t_main *main_struc)
{
	t_vp	*vp;

	vp = &main_struc->viewport;
	vp->mlx = mlx_init();
	vp->win_ptr = mlx_new_window(vp->mlx, WINDOW_WIDTH, \
	WINDOW_HEIGHT, "Cub3D");
	vp->img.mlx_img = mlx_new_image(vp->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	vp->img.addr = mlx_get_data_addr(vp->img.mlx_img, &vp->img.bpp, \
	&vp->img.line_len, &vp->img.endian);
}

void	*init_player(t_main *main_struc)
{
	t_player	*p;

	p = malloc(sizeof(t_player));
	p->pos.x = 2.5;
	p->pos.y = 2.5;
	p->dir.x = 1;
	p->dir.y = 0;
	p->cam_plane.x = 0;
	p->cam_plane.y = 0.66;
	p->map_x = (int)(p->pos.x);
	p->map_y = (int)(p->pos.y);
	// p->pos = get_pos();
	// p->dir = get_dir();
	// p->cam_plane = get_cam_plane();
	// p->map_x = (int)(p->pos.x);
	// p->map_y = (int)(p->pos.y);
	main_struc->player = p;
}


