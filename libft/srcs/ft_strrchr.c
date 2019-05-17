/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 10:40:13 by tmaze             #+#    #+#             */
/*   Updated: 2018/04/05 11:05:31 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tmp;
	char	*ret;

	i = -1;
	ret = NULL;
	tmp = (char*)s;
	while (++i == 0 || tmp[i - 1])
		if (tmp[i] == c)
			ret = &tmp[i];
	return (ret);
}
