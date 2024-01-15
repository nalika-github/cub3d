/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:38:38 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/14 19:18:27 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	set_player(t_player *p, t_map *m)
{
	(*p).pos = malloc(sizeof(t_coor));
	if (!(*p).pos)
		return (EXIT_FAILURE);
	(*p).pos->x = (((*p).map_x + 1) * m->maps) - (m->maps / 2) + (p->psize / 2);
	(*p).pos->y = (((*p).map_y + 1) * m->maps) - (m->maps / 2) + (p->psize / 2);
	return (EXIT_SUCCESS);
}

int	init_frame(t_frame *scene)
{
	(*scene).w = WINDOW_WIDTH;
	(*scene).h = WINDOW_HEIGHT;
	if (mapsize((*scene).map, (*scene).p))
		return (4);
	set_player((*scene).p, (*scene).map);  //set player position on map;
	return (EXIT_SUCCESS);
}
