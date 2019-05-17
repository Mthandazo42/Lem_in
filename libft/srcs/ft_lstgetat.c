/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:35:51 by tmaze             #+#    #+#             */
/*   Updated: 2018/04/09 16:45:36 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstgetat(t_list *lst, size_t ind)
{
	size_t	i;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	while (i != ind && tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (tmp);
}
