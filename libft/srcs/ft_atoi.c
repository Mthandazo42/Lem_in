/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:50:22 by tmaze             #+#    #+#             */
/*   Updated: 2019/03/16 15:37:42 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	nbnum;
	int	mult;
	int ret;

	nbnum = 0;
	while (str[nbnum] == ' ' || str[nbnum] == '\t' || str[nbnum] == '\n'
			|| str[nbnum] == '\v' || str[nbnum] == '\f' || str[nbnum] == '\r')
		nbnum++;
	if (str[nbnum] == '+' || str[nbnum] == '-')
		nbnum++;
	while (str[nbnum] != '\0' && ft_isdigit(str[nbnum]))
		nbnum++;
	nbnum--;
	ret = 0;
	mult = 1;
	while (nbnum >= 0 && ft_isdigit(str[nbnum]))
	{
		ret += (str[nbnum--] - '0') * mult;
		mult *= 10;
	}
	if (nbnum >= 0 && str[nbnum] == '-')
		ret *= -1;
	return (ret);
}
