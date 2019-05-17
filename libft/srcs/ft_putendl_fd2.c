/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:44:51 by tmaze             #+#    #+#             */
/*   Updated: 2019/03/20 17:00:16 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd2(char const *s, int fd)
{
	char	*str;

	if (s != NULL && (str = ft_strnew(ft_strlen(s) + 1)) != NULL)
	{
		ft_strcpy(str, s);
		ft_strcat(str, "\n");
		ft_putstr_fd(str, fd);
		ft_strdel(&str);
		return (0);
	}
	return (1);
}
