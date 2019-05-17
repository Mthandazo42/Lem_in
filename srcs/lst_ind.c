/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ind.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:56:55 by tmaze             #+#    #+#             */
/*   Updated: 2019/04/30 07:19:43 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ind	**lst_indinit(t_lmdata *data)
{
	data->adj = (t_ind**)ft_memalloc(sizeof(t_ind*) * data->nb_nodes);
	return (data->adj);
}

int		lst_indadd_link(t_lmdata *data, int n1, int n2)
{
	return (lst_indadd(&(data->adj[n1]), n2) && lst_indadd(&(data->adj[n2])
															, n1));
}

t_ind	*lst_indadd(t_ind **lst, int ind)
{
	t_ind	*new;

	if ((new = (t_ind*)ft_memalloc(sizeof(t_ind))) != NULL)
	{
		new->index = ind;
		new->weight = 1;
		new->next = *lst;
		*lst = new;
	}
	return (new);
}

void	lst_inddel(t_ind **lst)
{
	t_ind	*tmp;

	while (lst && *lst != NULL)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		ft_memdel((void**)&tmp);
	}
}

void	tablst_inddel(t_ind **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		lst_inddel(&(tab[i++]));
	ft_memdel((void**)&tab);
}
