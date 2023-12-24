/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:05:52 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/19 20:15:35 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../game_setup.h"

void    scene_init(t_var *vars)
{
    t_data  *img;
    t_frame *scene;
         
    img = (*vars).bgimg;
    scene = (*vars).scene;
    scene->bgc = 0x0034495E; 
    img->img = mlx_new_image((*vars).mlx, scene->w, scene->h);
    img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->llen, &img->endian);
}

void    minimap_init(t_var *vars)
{
    t_data  *img;
    t_map   *map;

    map = (*vars).scene->map; 
    img = (*vars).mini_img;
    img->img = mlx_new_image((*vars).mlx, map->mapx * map->maps, map->mapy * map->maps);
    img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->llen, &img->endian);    
}

int    display(t_var *vars)
{
    background(vars, (*vars).scene->bgc);
    minimap(vars, 0xCCBFC9CA);
    return (0);
}
