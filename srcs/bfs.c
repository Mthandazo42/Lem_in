/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 09:25:05 by tmaze             #+#    #+#             */
/*   Updated: 2019/04/30 07:08:31 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	bfs_init(t_lmdata *data, t_bfs *tab)
{
	int	i;

	i = 0;
	while (i < data->nb_nodes)
	{
		tab[i].queue = -1;
		tab[i].visited = 0;
		tab[i].parent = -1;
		i++;
	}
}

void	bfs_add_to_queue(t_lmdata *data, t_bfs *tab, int node, int i)
{
	int	j;

	j = 0;
	while (j < data->nb_nodes && tab[j].queue != -1
			&& tab[j].queue != node)
		j++;
	if (j < data->nb_nodes && tab[j].queue == -1)
	{
		tab[j].queue = node;
		tab[node].parent = tab[i].queue;
	}
}

void	bfs(t_lmdata *data, t_bfs *tab, int s_ind, int e_ind)
{
	int		i;
	int		used;
	t_ind	*it;

	i = 0;
	bfs_init(data, tab);
	tab[i].queue = s_ind;
	while (i < data->nb_nodes && tab[i].queue != -1 && tab[e_ind].parent == -1)
	{
		tab[tab[i].queue].visited = 1;
		used = (tab[tab[i].queue].old_visited
				&& get_node_path(data->adj[tab[tab[i].queue].parent]
								, tab[i].queue)->weight == 1);
		it = data->adj[tab[i].queue];
		while (it)
		{
			if (it->weight > 0 && !tab[it->index].visited
				&& (!used || (used && it->weight == 2)))
				bfs_add_to_queue(data, tab, it->index, i);
			it = it->next;
		}
		i++;
	}
}
