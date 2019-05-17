/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 11:55:11 by tmaze             #+#    #+#             */
/*   Updated: 2018/04/27 18:04:14 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t src_len;

	if (dst != NULL && src != NULL)
	{
		src_len = (size_t)ft_strlen(src);
		dst = ft_strncpy(dst, src, (src_len > size) ? size : src_len);
		dst[(src_len > size) ? size - 1 : src_len] = '\0';
	}
	return ((src != NULL) ? ft_strlen(src) : 0);
}
