/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:58:10 by tmaze             #+#    #+#             */
/*   Updated: 2018/04/09 18:06:26 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lowcase(char *c)
{
	*c = ft_tolower(*c);
}

char		*ft_strlowcase(char *s)
{
	ft_striter(s, &ft_lowcase);
	return (s);
}
