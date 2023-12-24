/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptungbun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:59:48 by ptungbun          #+#    #+#             */
/*   Updated: 2022/03/25 15:39:57 by ptungbun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*room;

	room = (void *)malloc(nmemb * size);
	if (!room)
		return (0);
	ft_bzero(room, nmemb * size);
	return (room);
}
