/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01map_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:01:21 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/15 12:40:26 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_main_struct(t_main *main_struc)
{
	main_struc->viewport = NULL;
	main_struc->map = NULL;
	main_struc->player = NULL;
	main_struc->ray = NULL;
	main_struc->wall_strip_width = 0;
	main_struc->cur_time = 0;
	main_struc->old_time = 0;
	main_struc->on_minimap = 1; // 1 = on, 0 = off and display just wall
}

int	is_invalid_input(char *argv, t_main *main)
{
	t_vp		*vars;

	(*main).viewport = (t_vp*)malloc(sizeof(t_vp));
	vars = (*main).viewport;
	vars->scene = (t_frame*)malloc(sizeof(t_frame));
	vars->bgimg = (t_imgdata*)malloc(sizeof(t_imgdata));
	vars->mini_img = (t_imgdata*)malloc(sizeof(t_imgdata));
	if (vars == NULL || vars->scene == NULL || vars->bgimg == NULL || \
	vars->mini_img == NULL)
		return (EXIT_FAILURE);
	init_scene(vars->scene);
	if (check_invalid_filedata(argv, vars->scene->map, vars->scene->p))
	{
		free_scene(&vars->scene);
		return (EXIT_FAILURE);
	}
	main->player = vars->scene->p;
	main->map = vars->scene->map;
	return (EXIT_SUCCESS);
}

void	del_nl(char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = *line;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
		{
			tmp[i] = '\0';
			break ;
		}
		i++;
	}
}

int	setup_pos(char *dir,int x, int y, t_player *p)
{
	if (p->one_player == false)
		p->one_player = true;
	else
		return (EXIT_FAILURE);
	p->map_x= x;
	p->map_y = y;
	p->D = *dir;
	return (EXIT_SUCCESS);
}

int	setup_pos_mapx(char **mapdata, int j, t_map *map, t_player *p)
{
	int		x;
	
	x = 0;
	while (mapdata[j][x])
	{
		if (mapdata[j][x] == 'N' || mapdata[j][x] == 'S' || mapdata[j][x] == 'W' || mapdata[j][x] == 'E')
		{
			if (setup_pos(&mapdata[j][x], x, j, p))
				return (EXIT_FAILURE);
		}
		else if (!(mapdata[j][x] == '0' || mapdata[j][x] == '1' || mapdata[j][x] == ' '))
			return (EXIT_FAILURE);
		x++;
	}
	if ((int)ft_strlen(mapdata[j]) > map->mapx)
		map->mapx = ft_strlen(mapdata[j]);
	return (EXIT_SUCCESS);	
}