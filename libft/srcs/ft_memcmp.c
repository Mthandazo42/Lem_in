/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:55:25 by tmaze             #+#    #+#             */
/*   Updated: 2018/04/08 13:41:54 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		diff;
	void	*str1;
	void	*str2;

	i = 0;
	diff = 0;
	str1 = (void*)s1;
	str2 = (void*)s2;
	if (n > 0)
		diff = ((unsigned char*)str1)[0] - ((unsigned char*)str2)[0];
	while (diff == 0 && ++i < n)
		diff = ((unsigned char*)str1)[i] - ((unsigned char*)str2)[i];
	return (diff);
}
