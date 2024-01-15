/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:05:52 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/14 20:33:43 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/game_setup.h"

void    init_vars(t_vp *vars)
{
    t_imgdata  *img;
    t_frame *scene;
         
    img = (*vars).bgimg;
    scene = (*vars).scene;
    scene->bgc = 0x0034495E; 
    img->img = mlx_new_image((*vars).mlx, scene->w, scene->h);
    img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->llen, &img->endian);
}

void    minimap_init(t_vp *vars)
{
    t_imgdata  *img;
    t_map   *map;

    map = (*vars).scene->map; 
    img = (*vars).mini_img;
    img->img = mlx_new_image((*vars).mlx, map->mapx * map->maps, map->mapy * map->maps);
    img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->llen, &img->endian);    
}

int    display(t_main *main)
{
	t_vp *vars;
	
	vars = (*main).viewport;
    background(vars, (*vars).scene->bgc);
//	cub3d_render(main, main->viewport);
    minimap(vars, 0xCCBFC9CA);
    return (0);
}
