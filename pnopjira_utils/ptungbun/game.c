/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:26:11 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/18 20:55:47 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../game_setup.h"

void	background(t_var *vars, unsigned int color)
{
    t_point upper_left;
    t_point lower_right;
    
    set_point(&upper_left, 0, 0, 0);
    set_point(&lower_right, (*vars).scene->w, (*vars).scene->h, 0);
    print_bg((*vars).bgimg, upper_left, lower_right, color);
    
	mlx_put_image_to_window((*vars).mlx, (*vars).win, (*vars).bgimg->img, 0, 0);
}
