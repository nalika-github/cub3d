/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_even.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:18:43 by ptungbun          #+#    #+#             */
/*   Updated: 2024/01/17 19:31:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

int	is_wall_block(t_main *m, int index)
{
	t_player	*p;
	int			**map;
	int			map_x;
	int			map_y;

	p = m->player;
	map = m->map;
	if (index == 0)
	{
		map_x = (int)(p->pos.x + p->dir.x * MOVE_SPEED);
		map_y = (int)(p->pos.y + p->dir.y * MOVE_SPEED);
	}
	if (index == 1)
	{
		map_x = (int)(p->pos.x - p->dir.x * MOVE_SPEED);
		map_y = (int)(p->pos.y - p->dir.y * MOVE_SPEED);
	}
	if (map[map_y][map_x] > 0)
		return (1);
	return (0);
}

void	move(t_main *m, int key)
{
	t_player	*p;

	p = m->player;
	if (key == KEY_W && !is_wall_block(m, 0))
	{
		p->pos.x += p->dir.x * MOVE_SPEED;
		p->pos.y += p->dir.y * MOVE_SPEED;
		p->map_x = (int)p->pos.x;
		p->map_y = (int)p->pos.y;
	}
	else if (key == KEY_S && !is_wall_block(m, 1))
	{
		p->pos.x -= p->dir.x * MOVE_SPEED;
		p->pos.y -= p->dir.y * MOVE_SPEED;
		p->map_x = (int)p->pos.x;
		p->map_y = (int)p->pos.y;
	}
}

void	move_forward_or_back(t_main *m, int key)
{
	t_player	*p;
	t_ray		*ray;
	t_vp		vp;
	int			i;

	vp = m->viewport;
	p = m->player;
	ray = m->ray;
	move(m, key);
	i = 0;
	while(i < WINDOW_WIDTH)
	{
		get_first_step_ray_dist(&ray[i], p);
		perform_dda(&ray[i], m->map, p);
		cal_ray_projection_dist_n_wall_hight(&ray[i]);
		ray_on_wall_pos_cal(m, &ray[i], p);
		i++;
	}
	ft_bzero(vp.img.addr, WINDOW_WIDTH * WINDOW_HEIGHT * vp.img.bpp / 8);
	mlx_clear_window(vp.mlx_ptr, vp.win_ptr);
	cub3d_render(m, &(m->viewport));
}

void	turn_left_or_right(t_main *m, int key)
{
	t_player	*p;
	t_ray		*ray;
	int			i;

	p = m->player;
	ray = m->ray;
	if (key == KEY_A || key == KEY_LEFT)
		rotate(m, 1);
	else
		rotate(m, -1);
	i = 0;
	while(i < WINDOW_WIDTH)
	{
		ray[i].raydir.x = p->dir.x + p->cam_plane.x * ray[i].lcpd;
		ray[i].raydir.y = p->dir.y + p->cam_plane.y * ray[i].lcpd;
		get_step_ray_dist(&ray[i]);
		get_first_step_ray_dist(&ray[i], p);
		perform_dda(&ray[i], m->map, p);
		cal_ray_projection_dist_n_wall_hight(&ray[i]);
		ray_on_wall_pos_cal(m, &ray[i], p);
		i++;
	}
	ft_bzero(m->viewport.img.addr, WINDOW_WIDTH * WINDOW_HEIGHT \
	* m->viewport.img.bpp / 8);
	mlx_clear_window(m->viewport.mlx_ptr, m->viewport.win_ptr);
	cub3d_render(m, &(m->viewport));
}

int	move_even(int key, t_main *main_struc)
{
	if (key == KEY_W || key == KEY_S)
		move_forward_or_back(main_struc, key);
	if (key == KEY_A || key == KEY_LEFT || key == KEY_D || key == KEY_RIGHT)
		turn_left_or_right(main_struc, key);
	return (0);
}
