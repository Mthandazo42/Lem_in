/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:27:26 by tmaze             #+#    #+#             */
/*   Updated: 2019/03/08 13:38:29 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_file	*ft_open(char *filename, oint oflag)
{
	t_file *ret;

	if ((ret = ft_memalloc(sizeof(t_file))) == NULL)
		return (NULL);
	if ((ret->fd = open(filename, oflag)) == -1)
	{
		ft_memdel(&ret);
		return (NULL);
	}
	ft_bzero(ret->buff, BUFF_SIZE + 1);
	return (ret);
}
