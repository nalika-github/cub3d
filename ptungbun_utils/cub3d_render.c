/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:46:33 by ptungbun          #+#    #+#             */
/*   Updated: 2024/01/17 18:13:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

// int	get_color(char *hex)
// {
// 	int		i;
// 	int		j;
// 	int		color;
// 	char	*hextext;

// 	i = 0;
// 	color = 0;
// 	while (hex[i])
// 	{
// 		hex[i] = (char)ft_tolower(hex[i]);
// 		i++;
// 	}
// 	i--;
// 	hextext = "0123456789abcdef";
// 	while (i >= 2)
// 	{
// 		j = 0;
// 		while (hextext[j] != hex[i])
// 			j++;
// 		color = color + j * pow(16, -1 * (i - 7));
// 		i--;
// 	}
// 	return (color);
// }

void	get_y(t_ray ray, int *y1, int *y2, int index)
{
	if(index == 0)
	{
		*y1 = 0;
		*y2 = ray.wall_y_start - 1;
	}
	else if(index == 1)
	{
		*y1 = ray.wall_y_start;
		*y2 = ray.wall_y_end;
	}
	else if(index == 2)
	{
		*y1 = ray.wall_y_end + 1;
		*y2 = WINDOW_HEIGHT;
	}
}

void	cub3d_render(t_main *ms, t_vp *vp)
{
	int		y[2];
	int		x[2];
	int		i;

	i = 0;
	while(i < WINDOW_WIDTH)
	{
		x[0] = i;
		x[1] = i;
		get_y(ms->ray[i], &y[0], &y[1], 0);
		drawline(&(vp->img), x, y, ms->ceiling_color);
		get_y(ms->ray[i], &y[0], &y[1], 1);
		draw_wall(ms, i, y, &ms->ray[i]);
		get_y(ms->ray[i], &y[0], &y[1], 2);
		drawline(&(vp->img), x, y, ms->floor_color);
		i++;
	}
	mlx_put_image_to_window(vp->mlx_ptr, vp->win_ptr, vp->img.mlx_img, 0, 0);
}
