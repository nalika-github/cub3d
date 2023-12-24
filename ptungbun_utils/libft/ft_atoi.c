/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:02:12 by ptungbun          #+#    #+#             */
/*   Updated: 2023/03/31 11:43:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	sign_toint(char c)
{
	if (c == '-')
		return (-1);
	else if (c == '+')
		return (1);
	return (1);
}

static int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' )
		return (1);
	if (c == '\f' || c == '\r' || c == ' ' )
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	num = 0;
	sign = 1;
	while (is_space(str[i]))
		i++;
	if (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
	{
		sign = sign_toint(str[i]);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * sign);
}
