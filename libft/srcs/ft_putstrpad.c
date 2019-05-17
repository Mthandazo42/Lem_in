/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrpad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 13:36:56 by tmaze             #+#    #+#             */
/*   Updated: 2018/07/31 14:05:41 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrpad(char *str, size_t size, char pad, char align)
{
	if (align == 'd')
		while (size-- != 0)
			ft_putchar(pad);
	ft_putstr(str);
	if (align == 'g')
		while (size-- != 0)
			ft_putchar(pad);
}
