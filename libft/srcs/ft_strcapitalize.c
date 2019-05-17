/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 11:16:16 by tmaze             #+#    #+#             */
/*   Updated: 2018/04/09 11:31:18 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 || !ft_isalnum(str[i - 1]))
			str[i] = ft_toupper(str[i]);
		else if (ft_isalnum(str[i - 1]))
			str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}
