/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 00:35:42 by tmaze             #+#    #+#             */
/*   Updated: 2018/04/08 17:15:34 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ret;

	if ((ret = (t_list*)malloc(sizeof(t_list))) != NULL)
	{
		if (!content)
		{
			ret->content = NULL;
			ret->content_size = 0;
		}
		else
		{
			if ((ret->content = malloc(content_size)) == NULL)
			{
				free(ret);
				return (0);
			}
			ft_memmove(ret->content, content, content_size);
			ret->content_size = content_size;
		}
		ret->next = NULL;
	}
	return (ret);
}
