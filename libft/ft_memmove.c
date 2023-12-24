/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:49:16 by pnopjira          #+#    #+#             */
/*   Updated: 2022/04/17 10:44:59 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *to, const void *from, size_t numBytes)
{
	unsigned char	*d;
	unsigned char	*s;

	s = (unsigned char *)from;
	d = to;
	if (!to && !from)
		return (NULL);
	if (to < from)
	{
		while (numBytes-- > 0)
			*d++ = *s++;
	}
	else
	{
		s = s + (numBytes - 1);
		d = d + (numBytes - 1);
		while (numBytes-- > 0)
			*d-- = *s--;
	}
	return (to);
}
