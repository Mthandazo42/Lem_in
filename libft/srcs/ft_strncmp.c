/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:04:21 by tmaze             #+#    #+#             */
/*   Updated: 2019/03/16 15:50:07 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;
	int diff;

	i = 1;
	diff = 0;
	if (n > 0)
		diff = (unsigned char)s1[0] - (unsigned char)s2[0];
	while ((unsigned int)i < n && diff == 0 && (unsigned char)s1[i - 1]
			&& (unsigned char)s2[i - 1])
	{
		diff = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	return (diff);
}
