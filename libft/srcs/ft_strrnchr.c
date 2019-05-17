/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrnchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 12:05:03 by tmaze             #+#    #+#             */
/*   Updated: 2018/05/16 12:32:26 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrnchr(const char *s, int c, int n)
{
	int		s_len;
	char	*tmp;

	s_len = ft_strlen(s);
	tmp = (char*)s;
	n = (s_len < n) ? s_len : n;
	s_len = s_len - n;
	while (n >= 0)
		if (tmp[s_len + n--] == c)
			return (&tmp[s_len + n + 1]);
	return (NULL);
}
