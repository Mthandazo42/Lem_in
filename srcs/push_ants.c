/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 11:37:56 by tmaze             #+#    #+#             */
/*   Updated: 2019/04/30 07:05:43 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	clean_ants(t_ants **ants)
{
	t_ants	*it;
	t_ants	*tmp;

	while (*ants && (*ants)->end)
	{
		tmp = *ants;
		*ants = (*ants)->next;
		ft_memdel((void**)&tmp);
	}
	it = *ants;
	while (it && it->next)
	{
		if (it->next->end)
		{
			tmp = it->next;
			it->next = tmp->next;
			ft_memdel((void**)&tmp);
		}
		else
			it = it->next;
	}
}

static void	print_ants(t_lmdata *data, t_ants **ants, t_ind **paths)
{
	t_ants	*it;

	it = *ants;
	while (it)
	{
		ft_printf("L%d-%s", it->nb_ant, get_node(data, it->nb_node)->name);
		if (get_node_path(paths[it->nb_path], it->nb_node)
			&& get_node_path(paths[it->nb_path], it->nb_node)->next)
			it->nb_node = get_node_path(paths[it->nb_path]
										, it->nb_node)->next->index;
		else
			it->end = 1;
		if (it->next)
			ft_putchar(' ');
		else
			ft_putchar('\n');
		it = it->next;
	}
	clean_ants(ants);
}

int			push_ants(t_lmdata *data, t_ind **paths, int nb_paths)
{
	t_ants	*ants;
	int		ant_c;
	int		i;

	ants = NULL;
	i = 0;
	ant_c = 2;
	while (paths[i] && paths[i]->weight == 0)
		i++;
	if (add_ant(&ants, 1, i, paths) == NULL)
		return (0);
	while (ants || ant_c <= data->nbants)
	{
		while (++i < nb_paths)
			if (paths[i]->weight > 0)
			{
				if (!add_ant(&ants, ant_c++, i, paths))
					del_ants(&ants);
				if (!ants)
					return (0);
			}
		print_ants(data, &ants, paths);
		i = -1;
	}
	return (1);
}
