/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 11:20:12 by tmaze             #+#    #+#             */
/*   Updated: 2018/05/05 16:48:49 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_itoa(int n)
{
	unsigned long	mult;
	int				nb_nbr;
	int				sign;
	unsigned long	nbr;
	char			*ret;

	mult = 10;
	nb_nbr = 1;
	nbr = ft_abs(n);
	sign = (n < 0);
	while (mult <= nbr && (nb_nbr++))
		mult *= 10;
	nb_nbr += sign;
	if ((ret = ft_strnew(nb_nbr)) == NULL)
		return (NULL);
	nb_nbr = 0;
	if (sign && (++nb_nbr))
		ret[0] = '-';
	while (mult > 1)
	{
		ret[nb_nbr++] = '0' + ((nbr % mult) / (mult / 10));
		mult /= 10;
	}
	return (ret);
}
