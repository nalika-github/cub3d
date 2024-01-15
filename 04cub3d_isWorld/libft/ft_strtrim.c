/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:57:25 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/26 23:43:10 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	head_check(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (check_set(s1[i], set))
		i++;
	return (i);
}

static int	tail_check(const char *s1, const char *set)
{
	int		i;
	size_t	len;

	len = ft_strlen(s1);
	i = len - 1;
	while (check_set(s1[i], set))
	{
		i--;
	}
	return (i);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		start;
	int		end;
	char	*str;
	size_t	len;

	if (!s1)
		return (NULL);
	start = head_check(s1, set);
	end = tail_check(s1, set);
	len = end - start + 1;
	if (start > end)
		len = 0;
	str = (char *)malloc((sizeof(char) * len) + 1);
	if (!str)
		return (NULL);
	len = ft_strlcpy(str, &s1[start], len);
	return (str);
}
