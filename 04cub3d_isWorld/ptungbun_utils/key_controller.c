/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:26:34 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/14 20:24:37 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/game_setup.h"

int	is_wall_block(t_main *m, int index)
{
	t_player	*p;
	int			**map;
	int			map_x;
	int			map_y;

	p = m->player;
	map = m->map->map;
	if (index == 0)
	{
		map_x = (int)(p->pos->x + p->dir.x * MOVE_SPEED);
		map_y = (int)(p->pos->y + p->dir.y * MOVE_SPEED);
	}
	if (index == 1)
	{
		map_x = (int)(p->pos->x - p->dir.x * MOVE_SPEED);
		map_y = (int)(p->pos->y - p->dir.y * MOVE_SPEED);
	}
	printf("pos.x = %f\n", p->pos->x + p->dir.x * MOVE_SPEED);
	printf("pos.y = %f\n", p->pos->y + p->dir.y * MOVE_SPEED);
	printf("map_x = %d\n", map_x);
	printf("map_y = %d\n", map_y);
	printf("map = %d\n", map[map_y][map_x]);
	if (map[map_y][map_x] > 0)
	{
		printf("hit_the_wall\n");
		return (1);
	}
	return (0);
}

void	move(t_main *m, int key)
{
	t_player	*p;

	p = m->player;
	if (key == KEY_W && !is_wall_block(m, 0))
	{
		p->pos->x += p->dir.x * MOVE_SPEED;
		p->pos->y += p->dir.y * MOVE_SPEED;
		p->map_x = (int)p->pos->x;
		p->map_y = (int)p->pos->y;
	}
	else if (key == KEY_S && !is_wall_block(m, 1))
	{
		p->pos->x -= p->dir.x * MOVE_SPEED;
		p->pos->y -= p->dir.y * MOVE_SPEED;
		p->map_x = (int)p->pos->x;
		p->map_y = (int)p->pos->y;
	}
}

void	move_forward_or_back(t_main *m, int key)
{
	t_player	*p;
	t_ray		*ray;
	t_vp		*vp;
	int			i;

	vp = m->viewport;
	p = m->player;
	ray = m->ray;
	move(m, key);
	i = 0;
	while(i < N_RAY)
	{
		get_first_step_ray_dist(&ray[i], p);
		perform_dda(&ray[i], m->map->map, p);
		cal_ray_projection_dist_n_wall_hight(&ray[i]);
		i++;
	}
	ft_bzero(vp->bgimg->addr, WINDOW_WIDTH * WINDOW_HEIGHT * vp->bgimg->bpp / 8);
	mlx_clear_window(vp->mlx, vp->win);
	cub3d_render(m, m->viewport);
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
	while(i < N_RAY)
	{
		ray[i].raydir.x = p->dir.x + p->cam_plane.x * ray[i].lcpd;
		ray[i].raydir.y = p->dir.y + p->cam_plane.y * ray[i].lcpd;
		get_step_ray_dist_n_ray_width(m->wall_strip_width, &ray[i], 1);
		get_first_step_ray_dist(&ray[i], p);
		perform_dda(&ray[i], m->map->map, p);
		cal_ray_projection_dist_n_wall_hight(&ray[i]);
		i++;
	}
	ft_bzero(m->viewport->bgimg->addr, WINDOW_WIDTH * WINDOW_HEIGHT * m->viewport->bgimg->bpp / 8);
	mlx_clear_window(m->viewport->mlx, m->viewport->win);
	cub3d_render(m, m->viewport);
}

int	bottons(int keycode, t_main *main)
{
   t_player	*p;
   t_frame	*s;

   p = main->player;
   s = main->viewport->scene;
   if (keycode == KEY_ESC)
   {
      printf(RED"\'ESC\' to Exit\n"RESET);
      free_on_exit(main->viewport);
	   exit(0);
   }
   else if (keycode == KEY_A  || keycode == KEY_LEFT || keycode == KEY_D || keycode == KEY_RIGHT)
         turn_left_or_right(main, keycode);
   else if (keycode == KEY_W || keycode == KEY_S)
		 move_forward_or_back(main, keycode);
	return (0);
}
