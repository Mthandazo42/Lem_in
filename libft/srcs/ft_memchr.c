/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:07:52 by tmaze             #+#    #+#             */
/*   Updated: 2018/04/06 16:27:54 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = (char*)s;
	while ((unsigned int)++i < n)
		if ((char)tmp[i] == (char)c)
			return ((void*)&tmp[i]);
	return (NULL);
}
