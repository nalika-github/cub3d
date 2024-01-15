/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_even.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:32:29 by ptungbun          #+#    #+#             */
/*   Updated: 2024/01/14 09:56:00 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycaster.h"

int	end_programe(t_main *main_struc)
{
	t_vp	vp;

	vp = main_struc->viewport;
	free(main_struc->ray);
	free(main_struc->player);
	mlx_clear_window(vp.mlx, vp.win_ptr);
	mlx_destroy_window(vp.mlx, vp.win_ptr);
	mlx_destroy_image(vp.mlx, vp.img.mlx_img);
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
