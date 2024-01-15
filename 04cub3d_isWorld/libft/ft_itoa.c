/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:58:14 by pnopjira          #+#    #+#             */
/*   Updated: 2022/04/13 15:11:01 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	size_num(long n)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		n *= (-1);
		i++;
	}
	if (n >= 0 && n <= 9)
		return (++i);
	else
	{
		while (n > 9)
		{
			n /= 10;
			i++;
		}
		i++;
		return (i);
	}
}

char	*toa(long i, int size, char *str)
{
	if (i > 9)
		str = toa((i / 10), (size - 1), str);
	str[size - 1] = (i % 10) + '0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*str;
	long	i;

	size = size_num(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	i = (long)n;
	if (!str)
		return (NULL);
	if (i < 0)
	{
		i *= -1;
		str[0] = '-';
	}
	str = toa(i, size, str);
	str[size] = '\0';
	return (str);
}
