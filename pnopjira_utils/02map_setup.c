/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02map_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:31:56 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/01 11:51:37 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_map_original(char **map_original, t_map **map, t_pos **p)
{
	char	**show_map;

	show_map = map_original;
	while (*show_map)
		printf("%s\n", *(show_map++));
	printf("px: %d, py: %d dir:%c\n", (*p)->p_pos->x, (*p)->p_pos->y, (*p)->dir);
	printf("mapx: %d, mapy: %d\n", (*map)->mapx, (*map)->mapy);
}

int	mapsize(t_map *m, t_pos *p)
{
	if (((*m).mapx > 12 || (*m).mapy > 12) && \
	((*m).mapx >= 3 && (*m).mapy >= 3))
	{
		if ((*m).mapx <= 38 && (*m).mapy <= 38)
			(*m).maps = 18;
		else
			return (EXIT_FAILURE);
	}
	else
	{
		if ((*m).mapx < 3 || (*m).mapy < 3)
			return (EXIT_FAILURE);
		else
			(*m).maps = 36;
	}
	if ((*m).maps == 18)
		(*p).ms = 6;
	else if ((*m).maps == 36)
		(*p).ms = 12;
	return (EXIT_SUCCESS);
}

void	key_to_content(void **iden, char *key, char *content)
{
	t_list	*tmp;

	tmp = *iden;
	while (tmp)
	{
		if (ft_strncmp(tmp->key, key, ft_strlen(key)) == 0)
		{
			if (tmp->content)
				free(tmp->content);
			tmp->content = ft_strdup(content);
			return ;
		}
		tmp = tmp->next;
	}
}