/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main_struc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:05:31 by ptungbun          #+#    #+#             */
/*   Updated: 2024/01/17 18:29:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void	init_main_struc(t_main *ms)
{
	ms->one_player = 0;
	init_viewport(ms);
	init_player(ms);
	init_ray(ms);
	ms->tex_so = "../textures/brick.xpm";
	ms->tex_no = "../textures/grey.xpm";
	ms->tex_we = "../textures/wood.xpm";
	ms->tex_ea = "../textures/blue.xpm";
	ms->viewport.tex_so_img = get_tex_image(&ms->viewport ,ms->tex_so ,\
	&ms->tex_width, &ms->tex_hight);
	ms->viewport.tex_no_img = get_tex_image(&ms->viewport ,ms->tex_no ,\
	&ms->tex_width, &ms->tex_hight);
	ms->viewport.tex_we_img = get_tex_image(&ms->viewport ,ms->tex_we ,\
	&ms->tex_width, &ms->tex_hight);
	ms->viewport.tex_ea_img = get_tex_image(&ms->viewport ,ms->tex_ea ,\
	&ms->tex_width, &ms->tex_hight);
	ms->ceiling_color = 8900331;
	ms->floor_color = 8707586;
}

t_image	get_tex_image(t_vp *vp, char *path, int *w, int *h)
{
	t_image	img;

	img.mlx_img = mlx_xpm_file_to_image(vp->mlx_ptr, path, w, h);
	if (img.mlx_img == NULL)
	{
		printf("image path: %s not found\n", path);
		return (img);
	}
	img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, \
	&img.line_len, &img.endian);
	return (img);
}

void	init_viewport(t_main *main_struc)
{
	t_vp	*vp;

	vp = &main_struc->viewport;
	vp->mlx_ptr = mlx_init();
	vp->win_ptr = mlx_new_window(vp->mlx_ptr, WINDOW_WIDTH, \
	WINDOW_HEIGHT, "Cub3D");
	vp->img.mlx_img = mlx_new_image(vp->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	vp->img.addr = mlx_get_data_addr(vp->img.mlx_img, &vp->img.bpp, \
	&vp->img.line_len, &vp->img.endian);
	main_struc->tex_width = TEX_WIDTH;
	main_struc->tex_hight = TEX_HIGHT;
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


