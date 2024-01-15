/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:52:12 by ptungbun          #+#    #+#             */
/*   Updated: 2024/01/13 19:33:03 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycaster.h"

void	imgpixelput(t_image *img, int x, int y, int color)
{
	char	*pixel;
	int		ww;
	int		wh;

	ww = WINDOW_WIDTH;
	wh = WINDOW_HEIGHT;
	if (x > 0 && x <= ww && y > 0 && y <= wh)
	{
		pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int *)pixel = color;
	}
}

void	bresenham_x(t_image *img, int *x, int *y, int color)
{
	int	xo;
	int	yo;
	int	pk;

	pk = 2 * abs(y[1] - y[0]) - abs(x[1] - x[0]);
	xo = x[0];
	yo = y[0];
	while (xo <= x[1])
	{
		imgpixelput(img, xo, yo, color);
		if (xo > x[1])
			xo--;
		else
			xo++;
		if (pk < 0)
			pk = pk + 2 * abs(y[1] - y[0]);
		else
		{
			pk = pk + 2 * abs(y[1] - y[0]) - 2 * abs(x[1] - x[0]);
			if (yo > y[1])
				yo--;
			else
				yo++;
		}
	}
}

void	bresenham_y(t_image *img, int *x, int *y, int color)
{
	int	xo;
	int	yo;
	int	pk;

	pk = 2 * abs(x[1] - x[0]) - abs(y[1] - y[0]);
	xo = x[0];
	yo = y[0];
	while (yo <= y[1])
	{
		imgpixelput(img, xo, yo, color);
		if (yo > y[1])
			yo--;
		else
			yo++;
		if (pk < 0)
			pk = pk + 2 * abs(x[1] - x[0]);
		else
		{
			pk = pk + 2 * abs(x[1] - x[0]) - 2 * abs(y[1] - y[0]);
			if (xo > x[1])
				xo--;
			else
				xo++;
		}
	}
}

static void	swap(int *x, int *y)
{
	int	temp;

	temp = x[0];
	x[0] = x[1];
	x[1] = temp;
	temp = y[0];
	y[0] = y[1];
	y[1] = temp;
}

void	drawline(t_image *img, int *x, int *y, int color)
{
	int	dx;
	int	dy;

	dx = abs(x[0] - x[1]);
	dy = abs(y[0] - y[1]);
	if (dx > dy)
	{
		if (x[0] > x[1])
			swap(x, y);
		bresenham_x(&(*img), x, y, color);
	}
	else
	{
		if (y[0] > y[1])
			swap(x, y);
		bresenham_y(&(*img), x, y, color);
	}
}
