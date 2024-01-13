/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_even.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:32:29 by ptungbun          #+#    #+#             */
/*   Updated: 2024/01/12 16:08:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

int	end_programe(t_main *main_struc)
{
	t_vp	vp;

	vp = main_struc->viewport;
	free(main_struc->ray);
	free(main_struc->player);
	mlx_clear_window(vp.mlx_ptr, vp.win_ptr);
	mlx_destroy_window(vp.mlx_ptr, vp.win_ptr);
	mlx_destroy_image(vp.mlx_ptr, vp.img.mlx_img);
	exit(0);
}

int	exit_even(int key, t_main *main_struc)
{
	if (key == KEY_ESC)
	{
		end_programe(main_struc);
	}
	return (0);
}
