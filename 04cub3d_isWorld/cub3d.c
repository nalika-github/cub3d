/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:26:37 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/14 21:49:57 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"
#include "./include/game_setup.h"

int	check_invalid_filedata(char *maps_path, t_map **map, t_player **p)
{
	if (invalid_filepath(maps_path, "maps/", ".cub"))
		return (ft_putstr_fd(GREEN"Used: maps/<filename>.cub\n"RESET, 2), \
		EXIT_FAILURE);
	if (explicit_error(rd_mapdata(maps_path, map, p)))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	raycaster_loop(t_main *main)
{
	t_vp	*vars;
	t_coor	pos;

	vars = (*main).viewport;
	if (explicit_error(init_frame(vars->scene)))
	 	return (EXIT_FAILURE);
	(*main).wall_strip_width = vars->bgimg->llen / (N_RAY - 1);
	vars->scene->p->pos = &pos;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->scene->w, \
	vars->scene->h, "isWorld-cub3D");
	init_vars(vars);
	minimap_init(vars);
	mlx_hook(vars->win, 17, 0, free_on_exit, vars);
	mlx_hook(vars->win, 2, 0, bottons, main);
	mlx_loop_hook(vars->mlx, display, main);
	mlx_loop(vars->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_main	main_struc;
	
	init_main_struct(&main_struc);
	if (argc != 2)
		return (perror(GREEN"USED: ./cud3d maps/<filename>.cub"RESET), \
		EXIT_FAILURE);
	if(is_invalid_input(argv[1], &main_struc))
		return (cub3d_exit(&main_struc), EXIT_FAILURE);
	raycaster_loop(&main_struc);
	return (EXIT_SUCCESS);
}
