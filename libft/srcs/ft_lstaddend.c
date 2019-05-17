/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 20:55:26 by tmaze             #+#    #+#             */
/*   Updated: 2018/11/26 12:30:30 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstaddend(t_list **alst, t_list *new)
{
	t_list *tmp;

	if (new == NULL)
		return (NULL);
	if (ft_lstsize(*alst) == 0)
		ft_lstadd(alst, new);
	else if (ft_lstsize(*alst) > 0)
	{
		tmp = ft_lstgetlast(*alst);
		ft_lstadd(&(tmp->next), new);
	}
	return (*alst);
}
