/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 23:12:24 by ptungbun          #+#    #+#             */
/*   Updated: 2023/03/04 00:04:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstpop_top(t_list **lst)
{
	t_list	*pop;

	if (ft_lstsize(*lst) == 0)
		return (0);
	pop = *lst;
	(*lst) = (*lst)->next;
	pop->next = NULL;
	return (pop);
}
