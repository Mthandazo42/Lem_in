/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 19:54:31 by tmaze             #+#    #+#             */
/*   Updated: 2018/04/10 14:31:03 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstdelmem(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*new;

	ret = NULL;
	if (lst != NULL && f != NULL)
	{
		if (lst->next != NULL)
			ret = ft_lstmap(lst->next, f);
		if ((new = (*f)(lst)) == NULL)
			ft_lstdel(&ret, &ft_lstdelmem);
		else
			ft_lstadd(&ret, new);
	}
	return (ret);
}
