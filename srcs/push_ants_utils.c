/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ants_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 11:23:36 by tmaze             #+#    #+#             */
/*   Updated: 2019/05/02 14:33:30 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ants	*add_ant(t_ants **ants, int nb_ant, int nb_path, t_ind **paths)
{
	t_ants	*new;
	t_ants	*it;

	if ((new = (t_ants*)ft_memalloc(sizeof(t_ants))) != NULL)
	{
		new->nb_ant = nb_ant;
		new->nb_path = nb_path;
		new->nb_node = paths[nb_path]->index;
		new->end = 0;
		new->next = NULL;
		if (*ants == NULL)
			*ants = new;
		else
		{
			it = *ants;
			while (it->next)
				it = it->next;
			it->next = new;
		}
		paths[nb_path]->weight--;
	}
	return (new);
}

void	del_ants(t_ants **ants)
{
	t_ants	*tmp;

	while (*ants)
	{
		tmp = *ants;
		*ants = (*ants)->next;
		ft_memdel((void**)&tmp);
	}
}

t_node	*get_node(t_lmdata *data, int index)
{
	t_node	*it;

	it = data->nodes_data;
	while (it && it->ind != index)
		it = it->next;
	return (it);
}

t_ind	*get_node_path(t_ind *lst, int index)
{
	t_ind	*it;

	it = lst;
	while (it && it->index != index)
		it = it->next;
	return (it);
}

void	push_ants_end(t_lmdata *data, char *e_name)
{
	int	i;

	i = 1;
	while (i <= data->nbants)
	{
		ft_printf("L%d-%s", i, e_name);
		if (i != data->nbants)
			ft_putchar(' ');
		i++;
	}
	ft_printf("\n");
}
