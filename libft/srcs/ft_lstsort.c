/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 11:54:22 by tmaze             #+#    #+#             */
/*   Updated: 2018/10/01 12:42:27 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list **lst, int (*f)(void *c1, void *c2), int rev)
{
	t_list	*sorted;
	t_list	*ind;
	t_list	*next;

	ind = *lst;
	sorted = NULL;
	while (ind)
	{
		next = ind->next;
		ft_lstaddsort(&sorted, ind, (*f), rev);
		ind = next;
	}
	*lst = sorted;
}
