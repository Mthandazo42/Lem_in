/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 17:00:34 by tmaze             #+#    #+#             */
/*   Updated: 2018/04/10 14:15:23 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		in_word;
	size_t	i;
	size_t	start;
	size_t	len;

	i = 0;
	if (s != NULL)
	{
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		start = i;
		in_word = 1;
		while (i == 0 || s[i - 1])
		{
			if (in_word && (!ft_isprint(s[i]) || s[i] == ' '))
			{
				len = i - start;
				in_word = 0;
			}
			else if (!in_word && ft_isprint(s[i]) && s[i] != ' ')
				in_word = 1;
			i++;
		}
	}
	return ((s != NULL) ? ft_strsub(s, start, len) : NULL);
}
