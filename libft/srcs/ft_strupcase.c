/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:08:19 by tmaze             #+#    #+#             */
/*   Updated: 2018/04/09 18:09:55 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_upcase(char *c)
{
	*c = ft_toupper(*c);
}

char		*ft_strupcase(char *s)
{
	ft_striter(s, &ft_upcase);
	return (s);
}
