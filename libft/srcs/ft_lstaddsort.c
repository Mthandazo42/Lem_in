/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 11:57:25 by tmaze             #+#    #+#             */
/*   Updated: 2018/10/02 16:43:09 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddsort(t_list **lst, t_list *new, int (*f)(void *c1, void *c2),
						int rev)
{
	t_list	**sort;

	sort = lst;
	if (*lst == NULL || (!rev && (*f)((*lst)->content, new->content) > 0)
		|| (rev && (*f)((*lst)->content, new->content) < 0))
		ft_lstadd(lst, new);
	else
	{
		while ((*sort) && ((rev && (*f)((*sort)->content, new->content) >= 0)
					|| (!rev && (*f)((*sort)->content, new->content) <= 0)))
			sort = &(*sort)->next;
		ft_lstadd(&(*sort), new);
	}
}
