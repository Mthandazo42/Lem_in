/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 14:32:30 by tmaze             #+#    #+#             */
/*   Updated: 2019/03/16 15:45:42 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	int		dest_len;

	dest_len = ft_strlen(dest);
	if ((size_t)dest_len < size)
	{
		ft_strncpy(&dest[dest_len], src, size - dest_len);
		dest[size - 1] = '\0';
	}
	return (((size_t)dest_len < size) ? (size_t)(dest_len + ft_strlen(src))
			: size + (size_t)ft_strlen(src));
}
