/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptungbun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:38:47 by ptungbun          #+#    #+#             */
/*   Updated: 2022/06/25 15:38:59 by ptungbun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strcat(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*buf;

	buf = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s1)
		return (0);
	i = 0;
	while (s1[i])
	{
		buf[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		buf[i + j] = s2[j];
		j++;
	}
	buf[i + j] = '\0';
	return (buf);
}
