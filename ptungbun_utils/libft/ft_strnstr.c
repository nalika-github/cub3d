/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:42:39 by ptungbun          #+#    #+#             */
/*   Updated: 2023/02/04 12:59:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static size_t	ft_isstrmatch(char *s1, char *s2, size_t i, size_t len)
{
	size_t	j;

	j = 0;
	while (s2[j] != '\0')
	{
		if (s1[i + j] != s2[j] || i + j >= len)
			return (0);
		j++;
	}
	return (1);
}

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	char	*buf_str;
	char	*buf_find;

	i = 0;
	buf_str = (char *)str;
	buf_find = (char *)find;
	if (!*buf_find)
		return (buf_str);
	while (buf_str[i] != '\0' && i < len)
	{
		if (ft_isstrmatch(buf_str, buf_find, i, len))
			return (buf_str + i);
		i++;
	}
	return (0);
}
