/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:06:49 by tmaze             #+#    #+#             */
/*   Updated: 2018/04/08 13:28:55 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	i = 0;
	if (src < dst)
	{
		i = len + 1;
		while (--i > 0)
			((char*)dst)[i - 1] = ((char*)src)[i - 1];
	}
	else if (src > dst)
		while (++i <= len)
			((char*)dst)[i - 1] = ((char*)src)[i - 1];
	return (dst);
}
