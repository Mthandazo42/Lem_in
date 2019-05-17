/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:55:29 by tmaze             #+#    #+#             */
/*   Updated: 2019/01/10 17:37:08 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	unsigned int i;

	i = -1;
	while (++i < n && (i == 0 || src[i - 1]))
		dest[i] = src[i];
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}
