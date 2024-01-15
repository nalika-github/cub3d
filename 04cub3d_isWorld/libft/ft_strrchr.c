/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:48:41 by pnopjira          #+#    #+#             */
/*   Updated: 2022/04/13 17:23:20 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*b;
	char	*ptr;

	ptr = NULL;
	b = (char *)ft_strchr(str, ch);
	while (b && *str != '\0')
	{
		ptr = b;
		str++;
		b = (char *)ft_strchr(str, ch);
	}
	if (*str == '\0' && ch % 256 == 0)
		return ((char *)str);
	return (ptr);
}
