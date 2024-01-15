/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:26:37 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/15 12:39:46 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"
#include "./include/game_setup.h"

int	check_invalid_filedata(char *maps_path, t_map *map, t_player *p)
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

	vars = (*main).viewport;
	if (set_vp(vars))
		return (cub3d_exit(main), EXIT_FAILURE);
	(*main).wall_strip_width = vars->bgimg->llen / (N_RAY - 1);
	printf("before init_ray\n");
	// init_ray(main); //SEGV on unknown address 0x000000000774 (pc 0x00010ee4f40d bp 0x7ffee0dbf350 sp 0x7ffee0dbf270 T0)
	printf("after init_ray\n");
	mlx_hook(vars->win, 17, 0, free_on_exit, vars);
	mlx_hook(vars->win, 2, 0, bottons, main);
	if (main->on_minimap)
    	mlx_loop_hook(vars->mlx, display_minimap, main);
	else
	{	// try to display wall in 2 way but didn't work at all, fixed init_ray() first.
		cub3d_render(main, main->viewport); // SEGV on unknown address 0x00000000005c (pc 0x00010c6b7fad bp 0x7ffee3551cc0 sp 0x7ffee3551ae0 T0)
		//mlx_loop_hook(vars->mlx, display, main);
	}
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
