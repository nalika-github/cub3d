/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:26:34 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/29 12:50:47 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../game_setup.h"

int	bottons(int keycode, t_var *vars)
{
   t_pos    *p;
   t_frame  *s;

   p = (*vars).scene->p;
   s = (*vars).scene;
   if (keycode == KEY_ESC)
   {
      printf(RED"\'ESC\' to Exit\n"RESET);
      free_on_exit(vars);
	   exit(0);
   }
   else if (keycode == KEY_A_LEFT)
      {
         if ((p->pos->x) - (p->ms / 3) > 0)
         {
            p->pos->x -= (p->ms / 3); 
            if (p->pos->x < (p->p_pos->x * s->map->maps) && p->pos->x < ((p->p_pos->x - 1) * s->map->maps) && (p->p_pos->x > 1))
               p->p_pos->x -= 1;
         }
         printf("pmx: %d, pmy: %d, pms: %d\n", p->p_pos->x, p->p_pos->y, p->p_pos->s);
      }
   else if (keycode == KEY_D_RIGHT) //
      {  
         if ((p->pos->x + p->ms) + (p->ms / 3) < (s->map->mapx * s->map->maps))
         {
            p->pos->x += (p->ms / 3); 
            if ((p->pos->x + p->ms) > (p->p_pos->x * s->map->maps) && (p->p_pos->x <= s->map->mapx))
               p->p_pos->x += 1;
         }
         printf("pmx: %d, pmy: %d, pms: %d\n", p->p_pos->x, p->p_pos->y, p->p_pos->s);
      }
   else if (keycode == KEY_W_UP)//
      {  
         if ((p->pos->y) - (p->ms / 3) > 0)
         {
            p->pos->y -= (p->ms / 3); 
            if (p->pos->y < (p->p_pos->y * s->map->maps) && p->pos->y < ((p->p_pos->y - 1) * s->map->maps) && (p->p_pos->y > 1))
               p->p_pos->y -= 1;
         }
         printf("pmx: %d, pmy: %d, pms: %d\n", p->p_pos->x, p->p_pos->y, p->p_pos->s);
      }
   else if (keycode == KEY_S_DOWN)//
      {  
         if ((p->pos->y + p->ms) + (p->ms / 3) < (s->map->mapy * s->map->maps))
         {
            p->pos->y += (p->ms / 3); 
            if ((p->pos->y + p->ms) > (p->p_pos->y * s->map->maps) && (p->p_pos->y <= s->map->mapy))
               p->p_pos->y += 1;
         }
         printf("pmx: %d, pmy: %d, pms: %d\n", p->p_pos->x, p->p_pos->y, p->p_pos->s);
      }
   else if (keycode == KEY_LEFT)
      {}
   else if (keycode == KEY_RIGHT)
      {}
	return (0);
}
