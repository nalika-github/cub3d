/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:38:38 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/01 12:04:29 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	set_player(t_pos *p, t_map *m)
{
	t_point	*pos;
	t_point	*mpos;

	pos = (*p).pos;
	mpos = (*p).p_pos;
	set_point(pos, ((mpos->x + 1) * m->maps) - (m->maps / 2) - (p->ms / 2), \
	((mpos->y + 1) * m->maps) - (m->maps / 2) - (p->ms / 2), p->ms);
	return (EXIT_SUCCESS);
}

int	init_frame(t_frame *scene)
{
	(*scene).w = 1440;
	(*scene).h = 810;
	if (mapsize((*scene).map, (*scene).p))
		return (4);
	set_player((*scene).p, (*scene).map);  //set player position on map;
	return (EXIT_SUCCESS);
}
