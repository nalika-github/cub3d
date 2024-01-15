/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:29:54 by ptungbun          #+#    #+#             */
/*   Updated: 2024/01/14 19:50:31 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	rotate(t_main *main_struc, double degree)
{
	double 		buf1;
	double 		buf2;
	double 		sint;
	double 		cost;
	t_player	*p;

	p = main_struc->player;
	sint = sin(degree * PI / 180);
	cost = cos(degree * PI / 180);
	buf1 = p->dir.x * cost + p->dir.y * sint;
	buf2 = p->dir.y * cost - p->dir.x * sint;
	p->dir.x = buf1;
	p->dir.y = buf2;
	buf1 = p->cam_plane.x * cost + p->cam_plane.y * sint;
	buf2 = p->cam_plane.y * cost - p->cam_plane.x * sint;
	p->cam_plane.x = buf1;
	p->cam_plane.y = buf2;
}
