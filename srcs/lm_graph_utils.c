/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_graph_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 07:17:06 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/05/09 17:26:36 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			is_link_in(t_lmdata *data, int src, int dest)
{
	t_ind			*it;

	if (src < data->nb_nodes)
	{
		it = data->adj[src];
		while (it)
		{
			if (it->index == dest)
				return (1);
			it = it->next;
		}
	}
	return (0);
}

void				lm_ext_conn_sub(t_holder *holder, t_temp *new_data)
{
	t_temp			*temp;

	temp = holder->data;
	while (temp->next)
		temp = temp->next;
	temp->next = new_data;
}

int					lm_adj_parser(t_lmdata *lmdata, t_holder *holder)
{
	t_temp			*data;

	if (holder != NULL)
	{
		data = holder->data;
		if (data != NULL)
		{
			while (data)
			{
				if (!is_link_in(lmdata, data->src_ind, data->dest_ind))
					lst_indadd_link(lmdata, data->src_ind, data->dest_ind);
				data = data->next;
			}
			return (1);
		}
	}
	return (0);
}
