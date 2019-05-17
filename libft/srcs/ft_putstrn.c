/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:20:52 by tmaze             #+#    #+#             */
/*   Updated: 2018/07/25 16:24:41 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrn(char	const *s, size_t nb)
{
	size_t	strlen;

	if (s != NULL)
	{
		strlen = ft_strlen(s);
		write(1, s, (nb < strlen) ? nb : strlen);
	}
}
