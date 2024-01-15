/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:23:53 by ptungbun          #+#    #+#             */
/*   Updated: 2024/01/14 11:54:08 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycaster.h"

void	*init_ray(t_main *main_struc)
{
	int			i;
	double		local_cam_plane_dist;
	t_ray		*ray;
	t_player	*p;

	ray = malloc(sizeof(t_ray) * N_RAY);
	p = main_struc->player;
	i = 0;
	while(i < N_RAY)
	{
		ray[i].index = i;
		ray[i].lcpd = 2 * ((double)i / (N_RAY - 1)) - 1;
		ray[i].raydir.x = p->dir.x + p->cam_plane.x * ray[i].lcpd;
		ray[i].raydir.y = p->dir.y + p->cam_plane.y * ray[i].lcpd;
		get_step_ray_dist_n_ray_width(main_struc->wall_strip_width, &ray[i], 1);
		get_first_step_ray_dist(&ray[i], p);
		perform_dda(&ray[i], main_struc->map->map, p);
		cal_ray_projection_dist_n_wall_hight(&ray[i]);
		i++;
	}
	main_struc->ray = ray;
}

void	get_step_ray_dist_n_ray_width(int wall_strip_width, t_ray *ray, int is_init)
{
	if(ray->raydir.x == 0)
		ray->step_rdx = 1e30;
	else
		ray->step_rdx = fabs(1.0 / ray->raydir.x);
	if(ray->raydir.y == 0)
		ray->step_rdy = 1e30;
	else
		ray->step_rdy = fabs(1.0 / ray->raydir.y);
	if (is_init == 1)
	{
		if (ray->index == 0)
		{
			ray->wall_x_start = 0;
			ray->wall_x_end = wall_strip_width / 2;
			return ;
		}
		else
			ray->wall_x_start = (ray - 1)->wall_x_end;
		ray->wall_x_end = ray->wall_x_start + wall_strip_width;
		if (ray->wall_x_end > (N_RAY - 1) * wall_strip_width)
			ray->wall_x_end = (N_RAY - 1) * wall_strip_width;
	}
}

void	get_first_step_ray_dist(t_ray *ray, t_player *p)
{
	if (ray->raydir.x < 0)
	{
		ray->step_side_x = -1;
		ray->rdx = (p->pos.x - (double)p->map_x) * ray->step_rdx;
	}
	else
	{
		ray->step_side_x = 1;
		ray->rdx = ((double)p->map_x + 1 - p->pos.x) * ray->step_rdx;
	}
	if (ray->raydir.y < 0)
	{
		ray->step_side_y = -1;
		ray->rdy = (p->pos.y - (double)p->map_y) * ray->step_rdy;
	}
	else
	{
		ray->step_side_y = 1;
		ray->rdy = ((double)p->map_y + 1 - p->pos.y) * ray->step_rdy;
	}
}

void	perform_dda(t_ray *ray, int **map, t_player *p)
{
	int	map_x;
	int	map_y;

	map_x = (int)p->pos.x;
	map_y = (int)p->pos.y;
	while(map[map_y][map_x] <= 0)
	{
		if(ray->rdx < ray->rdy)
		{
			ray->rdx += ray->step_rdx;
			map_x += ray->step_side_x;
			ray->wall_hit_side = 0;
		}
		else
		{
			ray->rdy += ray->step_rdy;
			map_y += ray->step_side_y;
			ray->wall_hit_side = 1;
		}
	}
}

void	cal_ray_projection_dist_n_wall_hight(t_ray *ray)
{
	if(ray->wall_hit_side == 0)
		ray->proj_dist = ray->rdx - ray->step_rdx;
	else
		ray->proj_dist = ray->rdy - ray->step_rdy;
	ray->wall_hight = (int)(WINDOW_HEIGHT / ray->proj_dist);
	ray->wall_y_start = (WINDOW_HEIGHT - ray->wall_hight) / 2;
	ray->wall_y_end = (WINDOW_HEIGHT + ray->wall_hight) / 2;
	if(ray->wall_y_start < 0)
		ray->wall_y_start = 0;
	if(ray->wall_y_end >= WINDOW_HEIGHT)
		ray->wall_y_end = WINDOW_HEIGHT;
}
