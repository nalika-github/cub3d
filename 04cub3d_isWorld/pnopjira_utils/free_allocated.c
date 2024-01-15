/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_allocated.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:42:34 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/14 21:24:34 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/game_setup.h"

void	del(void *lst)
{
	t_list	*tmp;

	tmp = (t_list *)lst;
	free(tmp->key);
	free(tmp->content);
	tmp->key = NULL;
	tmp->content = NULL;
}

void	free_scene(t_frame **scene)
{
	t_frame	*s;
	int		i;
	
	i = 0;
	s = *scene;
	ft_lstclear(&s->map->iden, del);
	if (s->map->map_original)
		while (s->map->map_original[i])
			free(s->map->map_original[i++]);
	free(s->map);
	free(s->p);
	s->map = NULL;
	s->p = NULL;
}

int	free_on_exit(t_vp *vars)
{
	mlx_destroy_image((*vars).mlx, (*vars).bgimg->img);
	mlx_destroy_image((*vars).mlx, (*vars).mini_img->img);
	mlx_destroy_window((*vars).mlx, (*vars).win);
	free_scene(&(*vars).scene);
	exit(0);
}

void	cub3d_exit(t_main *main_struc)
{
	(void)main_struc;
	exit(0);
}