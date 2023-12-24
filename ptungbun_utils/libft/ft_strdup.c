/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 03:11:12 by ptungbun          #+#    #+#             */
/*   Updated: 2023/09/14 19:05:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s)
{
	char	*room;
	size_t	len;

	len = ft_strlen(s) + 1;
	room = malloc(sizeof(char) * len);
	if (!room)
		return (0);
	return (ft_memcpy(room, s, len));
}
