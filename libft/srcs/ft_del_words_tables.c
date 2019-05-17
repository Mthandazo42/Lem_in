/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_words_tables.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 15:13:09 by tmaze             #+#    #+#             */
/*   Updated: 2018/07/25 16:03:19 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_del_words_tables(char ***word_table)
{
	int	i;

	i = -1;
	while ((*word_table)[++i])
		ft_strdel(&(*word_table)[i]);
	ft_memdel((void**)word_table);
	*word_table = NULL;
}
