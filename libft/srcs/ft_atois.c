/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atois.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:58:44 by tmaze             #+#    #+#             */
/*   Updated: 2019/03/16 15:47:50 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atois(const char *str, int *nb)
{
	int	num;
	int	mult;
	int	max;

	num = 0;
	while (ft_iswhitespace(str[num]))
		num++;
	max = (str[num] == '-') ? FT_INT_MIN : FT_INT_MAX;
	if (str[num] == '+' || str[num] == '-')
		num++;
	while (str[num] != '\0' && ft_isdigit(str[num]))
		num++;
	num--;
	*nb = 0;
	mult = 1;
	while (num >= 0 && ft_isdigit(str[num])
			&& (ft_abs(max - *nb) >= 2000000000))
	{
		*nb += (str[num--] - '0') * mult;
		mult *= 10;
	}
	if (num >= 0 && str[num] == '-')
		*nb *= -1;
	return (!ft_isdigit(str[num]) || ft_abs(max - *nb) >= 2000000000);
}
