/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 13:05:24 by tmaze             #+#    #+#             */
/*   Updated: 2018/05/05 16:50:14 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_putnbr_fd(int n, int fd)
{
	unsigned long	mult;
	int				nb_nbr;
	unsigned long	nbr;

	mult = 10;
	nbr = ft_abs(n);
	while (mult <= nbr)
		mult *= 10;
	if (n < 0)
		write(fd, "-", 1);
	while (mult > 1)
	{
		nb_nbr = '0' + ((nbr % mult) / (mult / 10));
		write(fd, &nb_nbr, 1);
		mult /= 10;
	}
}
