/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:57:43 by pnopjira          #+#    #+#             */
/*   Updated: 2022/03/26 15:48:08 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	append_array(char **array, int i, char **start, size_t n)
{
	size_t	j;
	char	*str;

	j = 0;
	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
	{
		while (j < n)
		{
			free(array[j++]);
		}
		free(array);
		return (0);
	}
	(void)ft_strlcpy(str, *start, n + 1);
	array[i] = str;
	*start = *start + n;
	return (1);
}

static size_t	cnt_size(const char *s, char c)
{
	char	*start;
	char	*end;
	size_t	cnt;

	cnt = 0;
	start = (char *)s;
	end = (char *)s;
	while (*s != '\0')
	{
		if (*s == c)
			end = (char *)s;
		if (end - start > 1 || (end - start > 0 && *start != c))
			cnt = cnt + 1;
		start = end;
		s++;
	}
	end = (char *)s;
	if (end - start > 1)
		cnt = cnt + 1;
	return (cnt + 1);
}

static int	cond_check(char **array, int *i, char **start, size_t n)
{
	char	*str;

	if (n > 1)
	{
		str = *start + 1;
		if (!append_array(array, *i, &str, n - 1))
			return (-1);
		*i = *i + 1;
		*start = *start + n;
		return (1);
	}
	*start = *start + n;
	return (0);
}

static int	cutting_string(const char *s, char c, char **array, char *start)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		if (*s++ == c)
		{
			if (((s - 1) - start > 0 && *start != c))
			{
				if (!append_array(array, i++, &start, (s - 1) - start))
					return (0);
			}
			if (cond_check(array, &i, &start, (s - 1) - start) < 0)
				return (0);
		}
	}
	if (((s - 1) - start > 0 && *start != c))
	{
		if (!append_array(array, i++, &start, s - start))
			return (0);
	}
	else if (cond_check(array, &i, &start, s - start) < 0)
		return (0);
	array[i] = 0;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	*start;
	char	**array;

	if (!s)
		return (NULL);
	start = (char *)s;
	array = (char **)malloc(sizeof(char *) * cnt_size(s, c));
	if (!array)
		return (NULL);
	if (!cutting_string(s, c, array, start))
		return (NULL);
	return (array);
}
