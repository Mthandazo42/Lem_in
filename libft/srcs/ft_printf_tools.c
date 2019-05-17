/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 21:49:45 by klebon            #+#    #+#             */
/*   Updated: 2019/03/07 22:18:16 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		init_struct_conv(t_conv *field)
{
	field->fl_minus = 0;
	field->fl_plus = 0;
	field->fl_zero = 0;
	field->fl_hashtag = 0;
	field->fl_space = 0;
	field->fl_witdth = 0;
	field->fl_prec = -1;
	field->fl_size = -1;
	field->fl_type = -1;
	field->str = NULL;
	field->str_size = 0;
}

char		*ft_strnewb(size_t size)
{
	size_t	i;
	char	*str;

	i = -1;
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (++i < (size + 1))
		str[i] = '\0';
	return (str);
}

uint64_t	dmod(long double nb, long double mod)
{
	uint64_t	res;

	res = (uint64_t)(nb - mod * (uint64_t)(nb / mod));
	return (res);
}
