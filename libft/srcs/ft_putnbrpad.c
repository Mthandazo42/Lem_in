/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrpad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 13:51:17 by tmaze             #+#    #+#             */
/*   Updated: 2018/07/31 14:04:43 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrpad(int nbr, size_t size, char pad, char align)
{
	if (align == 'd')
		while (size-- != 0)
			ft_putchar(pad);
	ft_putnbr(nbr);
	if (align == 'g')
		while (size-- != 0)
			ft_putchar(pad);
}
