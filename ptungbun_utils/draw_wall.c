/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:48:47 by ptungbun          #+#    #+#             */
/*   Updated: 2024/01/17 19:30:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void	ray_on_wall_pos_cal(t_main *ms, t_ray *ray, t_player *p)
{
	double	wall_x;

	if (ray->wall_hit_side == 0)
		wall_x = p->pos.y + ray->proj_dist * ray->raydir.y;
	if (ray->wall_hit_side == 1)
		wall_x = p->pos.x + ray->proj_dist * ray->raydir.x;
	wall_x -= floor((wall_x));;
	ray->tex_x = (int)(wall_x * (double)(ms->tex_width));
	if (ray->wall_hit_side == 0 && ray->raydir.x > 0)
		ray->tex_x = ms->tex_width - ray->tex_x - 1;
	if (ray->wall_hit_side == 1 && ray->raydir.y < 0)
		ray->tex_x = ms->tex_width - ray->tex_x - 1;
}

int	get_tex_color(t_image *tex_img, int x, int y)
{
	char	*pixel;

	pixel = tex_img->addr + (y * tex_img->line_len + x \
	* (tex_img->bpp / 8));
	return (*(int *)pixel);
}

t_image	*get_texture(t_ray ray, t_vp *vp)
{
	if (ray.wall_hit_side == 0)
	{
		if (ray.raydir.x > 0)
			return (&vp->tex_no_img);
		else
			return (&vp->tex_so_img);
	}
	else if (ray.wall_hit_side == 1)
	{
		if (ray.raydir.y > 0)
			return (&vp->tex_ea_img);
		else
			return (&vp->tex_we_img);
	}
	return (NULL);
}

void	draw_wall(t_main *ms ,int x, int *y, t_ray *ray)
{
	int		i;
	int		color;
	int		tex_y;
	t_image	*tex_img;

	tex_img = get_texture(*ray, &ms->viewport);
	i = y[0];
	while(i <= y[1])
	{
		color = get_tex_color(tex_img, ray->tex_x, \
		((int)(float)ms->tex_hight / (float)ray->wall_hight * (i - y[0])));
		imgpixelput(&ms->viewport.img, x, i, color);
		i++;
	}
}
