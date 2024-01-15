/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:38:57 by pnopjira          #+#    #+#             */
/*   Updated: 2023/04/17 23:48:42 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	os;

	os = 0;
	if (!src)
		return (0);
	while ((os) < dstsize)
	{
		dst[os] = src[os];
		os++;
	}
	if (dstsize > 0)
		dst[os] = '\0';
	return (ft_strlen(src));
}
