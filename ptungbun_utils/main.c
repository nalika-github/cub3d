/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:03:26 by ptungbun          #+#    #+#             */
/*   Updated: 2024/01/13 12:16:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

int	cub3d_exit(t_main *main_struc)
{
	return (0);
}

void	get_test_map(t_main *main_struc)
{
	int	i;
	int	j;
	int	test_map[5][5] = {{1, 1, 1, 1, 1}, {1, 0, 0, 0, 1,}, {1, 0, 0, 0, 1}, {1, 0, 0, 0, 1}, {1, 1, 1, 1, 1}};

	i = 0;
	j = 0;
	main_struc->map = malloc(sizeof(int *) * 5);
	while(i < 5)
	{
		j = 0;
		(main_struc->map)[i] = malloc(sizeof(int) * 5);
		while(j < 5)
		{
			(main_struc->map)[i][j] = test_map[i][j];
			j++;
		}
		i++;
	}
}

void	print_test_map(t_main *main_struc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(i < 5)
	{
		j = 0;
		while(j < 5)
		{
			printf("%d", (main_struc->map)[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_main	main_struc;

	(void)argc;
	(void)argv;
	get_test_map(&main_struc);
	// print_test_map(&main_struc);
	// if(is_invalid_input(argc, argv, &main_struc))
	// 	return (cub3d_exit(&main_struc));
	init_main_struc(&main_struc);
	cub3d_render(&main_struc, &(main_struc.viewport));
	mlx_hook(main_struc.viewport.win_ptr, 2, (1L<<0), move_even, &main_struc);
	mlx_key_hook(main_struc.viewport.win_ptr, exit_even, &main_struc);
	mlx_loop(main_struc.viewport.mlx_ptr);
	return (0);
}
