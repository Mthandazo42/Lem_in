/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 11:29:28 by tmaze             #+#    #+#             */
/*   Updated: 2018/04/06 11:30:21 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (++i <= n)
	{
		((char*)dest)[i - 1] = ((char*)src)[i - 1];
		if (((unsigned char*)src)[i - 1] == (unsigned char)c)
			return (dest + i);
	}
	return (NULL);
}
