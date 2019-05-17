/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:35:03 by tmaze             #+#    #+#             */
/*   Updated: 2019/03/16 15:52:25 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	tmp = (char*)haystack;
	if (ft_strequ(needle, ""))
		return (tmp);
	while ((++i == 0 || tmp[i - 1]) && i < (int)len)
		if (tmp[i] == needle[0] && (j = 1))
		{
			while (tmp[i + j] == needle[j] && needle[j] && tmp[i + j]
					&& (i + j) < (int)len)
				j++;
			if (needle[j] == '\0')
				return (&tmp[i]);
		}
	return (NULL);
}
