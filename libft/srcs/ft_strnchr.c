/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 11:41:02 by tmaze             #+#    #+#             */
/*   Updated: 2018/10/08 15:21:15 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(const char *s, int c, int n)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = (char*)s;
	while ((++i == 0 || tmp[i - 1]) && n > 0 && i < n)
		if (tmp[i] == c)
			return (&tmp[i]);
	return (NULL);
}
