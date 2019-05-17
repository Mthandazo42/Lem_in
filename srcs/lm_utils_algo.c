/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_utils_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 11:50:04 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/04/30 07:19:29 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node					*get_node_role(t_lmdata *data, char role)
{
	t_node				*it;

	it = data->nodes_data;
	while (it)
	{
		if (it->role == role)
			return (it);
		it = it->next;
	}
	return (NULL);
}

int						get_nb_paths(t_ind **ret)
{
	int					index;

	index = 0;
	while (ret[index])
		index++;
	return (index);
}

void					get_nb_paths_max(t_lmdata *data, int start, int end)
{
	int					i;
	int					j;
	t_ind				*it;

	i = 0;
	j = 0;
	it = data->adj[start];
	while (it && ++i)
		it = it->next;
	it = data->adj[end];
	while (it && ++j)
		it = it->next;
	data->nb_paths_max = (i > j) ? j : i;
}
