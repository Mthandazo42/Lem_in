/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 09:59:11 by tmaze             #+#    #+#             */
/*   Updated: 2019/04/30 07:14:04 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		go_upstream(t_lmdata *data, t_ind **path, int s_ind, t_ind *it)
{
	int		nb_nodes;
	int		j;
	t_ind	*it2;

	nb_nodes = 1;
	j = it->index;
	while (j != s_ind)
	{
		lst_indadd(path, j);
		nb_nodes++;
		it2 = data->adj[j];
		while (it2 && it2->weight != 2)
			it2 = it2->next;
		if (it2 && it2->weight == 2)
			j = it2->index;
	}
	(*path)->weight = nb_nodes;
}

static t_ind	**resolve_paths(t_lmdata *data, int nb_paths, int s_ind
								, int e_ind)
{
	t_ind	**ret;
	t_ind	*it;
	int		i;

	if ((ret = (t_ind**)ft_memalloc(sizeof(t_ind*) * (nb_paths + 1))) != NULL)
	{
		i = 0;
		it = data->adj[e_ind];
		while (it && i < nb_paths)
		{
			if (it->weight == 2)
			{
				lst_indadd(&(ret[i]), e_ind);
				go_upstream(data, &(ret[i]), s_ind, it);
				i++;
			}
			it = it->next;
		}
	}
	return (ret);
}

static void		update_weights(t_lmdata *data, t_bfs *tab, int s_ind, int e_ind)
{
	int		i;
	t_ind	*it;

	i = e_ind;
	while (i != s_ind)
	{
		it = data->adj[i];
		while (it && it->index != tab[i].parent)
			it = it->next;
		if (it->index == tab[i].parent)
			it->weight++;
		it = data->adj[tab[i].parent];
		while (it && it->index != i)
			it = it->next;
		if (it)
			it->weight--;
		it = data->adj[i];
		while (it && it->weight == 1)
			it = it->next;
		tab[i].old_visited = (it && it->weight != 1);
		i = tab[i].parent;
	}
}

static void		cmp_scores(t_ind ***ret, int *scores)
{
	if (ret[0] == NULL || scores[1] < scores[0])
	{
		if (ret[0] != NULL)
			tablst_inddel(ret[0]);
		ret[0] = ret[1];
		scores[0] = scores[1];
	}
	else
		tablst_inddel(ret[1]);
}

t_ind			**edmonds_karp(t_lmdata *data, int s_ind, int e_ind)
{
	t_bfs	tab[data->nb_nodes];
	t_ind	**ret[2];
	int		nb_paths;
	int		scores[2];
	int		i;

	ret[0] = NULL;
	scores[0] = 0;
	nb_paths = 0;
	i = 0;
	while (i < data->nb_nodes)
		tab[i++].old_visited = 0;
	bfs(data, tab, s_ind, e_ind);
	while (tab[e_ind].parent != -1)
	{
		nb_paths++;
		update_weights(data, tab, s_ind, e_ind);
		ret[1] = resolve_paths(data, nb_paths, s_ind, e_ind);
		scores[1] = get_score(data, ret[1], nb_paths);
		cmp_scores(ret, scores);
		bfs(data, tab, s_ind, e_ind);
	}
	return (ret[0]);
}
