/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:46:33 by ptungbun          #+#    #+#             */
/*   Updated: 2024/01/14 09:56:08 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycaster.h"

int	get_color(char *hex)
{
	int		i;
	int		j;
	int		color;
	char	*hextext;

	i = 0;
	color = 0;
	while (hex[i])
	{
		hex[i] = (char)ft_tolower(hex[i]);
		i++;
	}
	i--;
	hextext = "0123456789abcdef";
	while (i >= 2)
	{
		j = 0;
		while (hextext[j] != hex[i])
			j++;
		color = color + j * pow(16, -1 * (i - 7));
		i--;
	}
	return (color);
}

void	cub3d_render(t_main *main_struc, t_vp *vp)
{
	int		y[2];
	int		x[2];
	int		i;
	t_ray	*ray;

	ray = main_struc->ray;
	i = 0;
	while(i < N_RAY)
	{
		x[0] = ray[i].wall_x_start;
		x[1] = x[0];
		y[0] = ray[i].wall_y_start;
		y[1] = ray[i].wall_y_end;
		while(x[0] <= ray[i].wall_x_end)
		{
			drawline(&(vp->img), x, y, 16777215);
			x[0]++;
			x[1] = x[0];
		}
		i++;
	}
	mlx_put_image_to_window(vp->mlx, vp->win_ptr, vp->img.mlx_img, 0, 0);
}
