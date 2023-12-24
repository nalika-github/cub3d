/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_n_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:56:55 by ptungbun          #+#    #+#             */
/*   Updated: 2023/09/14 16:53:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strcat_n_free(char *s1, char *s2)
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
	free(s1);
	free(s2);
	return (buf);
}
