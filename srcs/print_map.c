/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 17:35:29 by tmaze             #+#    #+#             */
/*   Updated: 2019/05/09 16:35:02 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	del_map(t_lmdata *data)
{
	t_rdata *tmp;

	if (data != NULL)
	{
		while (data->map)
		{
			tmp = data->map;
			data->map = data->map->next;
			ft_strdel(&(tmp->line));
			ft_memdel((void**)&tmp);
		}
	}
}

void	print_map(t_lmdata *data)
{
	t_rdata *it;

	it = data->map;
	while (it)
	{
		ft_printf("%s\n", it->line);
		it = it->next;
	}
	del_map(data);
	ft_printf("\n");
}

int		add_line_map(t_lmdata *data, char *line)
{
	t_rdata *it;
	t_rdata *new;

	if ((new = (t_rdata*)ft_memalloc(sizeof(t_rdata))) == NULL)
		return (1);
	new->line = line;
	new->next = NULL;
	if (data->map == NULL)
		data->map = new;
	else
	{
		it = data->map;
		while (it->next)
			it = it->next;
		it->next = new;
	}
	return (0);
}
