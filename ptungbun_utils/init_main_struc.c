/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main_struc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:05:31 by ptungbun          #+#    #+#             */
/*   Updated: 2023/12/24 13:14:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void	init_main_struc(t_main *main_struc)
{
	main_struc->cur_time = 0;
	main_struc->old_time = 0;
	main_struc->one_player = 0;
	init_player(main_struc);
	init_ray(main_struc);
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


