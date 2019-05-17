/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:28:43 by tmaze             #+#    #+#             */
/*   Updated: 2018/04/09 19:04:57 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_params(int ac, char **av)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (++i < ac && (j = i))
	{
		tmp = av[i];
		while (j > 1 && ft_strcmp(av[j - 1], tmp) > 0)
		{
			av[j] = av[j - 1];
			j--;
		}
		av[j] = tmp;
	}
}
