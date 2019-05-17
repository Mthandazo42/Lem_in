/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 14:57:22 by tmaze             #+#    #+#             */
/*   Updated: 2018/04/10 14:18:41 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	size_t	i;
	size_t	s_len;

	i = -1;
	s_len = 0;
	ret = NULL;
	if (s != NULL && f != NULL)
	{
		s_len = ft_strlen(s);
		if ((ret = ft_strnew(s_len)) != NULL)
			while (++i < s_len)
				ret[i] = (*f)(s[i]);
	}
	return (ret);
}
