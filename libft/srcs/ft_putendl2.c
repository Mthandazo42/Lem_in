/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:14:49 by tmaze             #+#    #+#             */
/*   Updated: 2019/03/20 17:00:52 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl2(char const *s)
{
	char	*str;

	if (s != NULL && (str = ft_strnew(ft_strlen(s) + 1)) != NULL)
	{
		ft_strcpy(str, s);
		ft_strcat(str, "\n");
		ft_putstr(str);
		ft_strdel(&str);
		return (0);
	}
	return (1);
}
