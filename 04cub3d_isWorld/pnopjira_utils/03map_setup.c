/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03map_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:53:43 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/13 20:56:06 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	char_to_int_map(char **o_map, t_map **plan)
{
	int		**n_map;
	const int	i = (*plan)->mapx;
	const int	j = (*plan)->mapy;
	int y;
	int x;

	y = 0;
	n_map = (int **)malloc(sizeof(int *) * j);
	while (y < j)
		n_map[y++] = (int *)malloc(sizeof(int) * i);
		
	y = 0;
	while(y < j)
	{	
		x = 0;
		while (o_map[y][x] != '\0')
		{
			if (o_map[y][x] == '1')
				n_map[y][x] = 1;
			else if (o_map[y][x] == ' ')
				n_map[y][x] = -1;
			else if (o_map[y][x] == '0')
				n_map[y][x] = 0;
			else 
				n_map[y][x] = 0;
			x++;
		}
		while (x < i)
		{
			n_map[y][x] = -1;
			x++;
		}
		y++;
	}
	(*plan)->map = n_map;
	return (EXIT_SUCCESS);
}

int	ck_map_info(t_map **map)
{
	if ((*map)->map_begin == 0)
	{
		(*map)->map_begin = 1;
		(*map)->mapy++;
	}
	else
	{
		(*map)->mapy++;
	}
	return (EXIT_SUCCESS);
}

//for test
void print_new_map(int ***map, int j, int i)
{
	int x;
	int y;

	y = 0;
	while (y < j)
	{
		x = 0;
		while (x < i)
		{
			printf("%d,", (*map)[y][x]);
			x++;
		}
		y++;
		printf("\n");
	}
}