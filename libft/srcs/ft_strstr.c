/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 10:54:41 by tmaze             #+#    #+#             */
/*   Updated: 2018/04/08 15:25:55 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	tmp = (char*)haystack;
	if (ft_strequ(needle, ""))
		return (tmp);
	while (++i == 0 || tmp[i - 1])
		if (tmp[i] == needle[0] && (j = 1))
		{
			while (tmp[i + j] == needle[j] && needle[j] && tmp[i + j])
				j++;
			if (needle[j] == '\0')
				return (&tmp[i]);
		}
	return (NULL);
}
