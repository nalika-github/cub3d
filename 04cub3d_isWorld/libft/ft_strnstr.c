/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:38:55 by pnopjira          #+#    #+#             */
/*   Updated: 2022/04/03 20:41:49 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*str;

	str = (char *)s1;
	if (*s2 != '\0')
	{
		if (ft_strlen(s2) > n)
			return (NULL);
		while (ft_strncmp(str, s2, ft_strlen(s2)) != 0)
		{
			if (*str == *s2)
			{
				n--;
				str++;
			}
			while (*str != *s2)
			{
				if (*str++ == '\0' || n-- < 1)
					return (NULL);
			}
			if (ft_strlen(s2) > n)
				return (NULL);
		}
	}
	return (str);
}
