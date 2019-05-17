/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:05:06 by tmaze             #+#    #+#             */
/*   Updated: 2019/04/30 07:05:10 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	init_scores(t_ind **ret, int *scores)
{
	int	i;

	i = 0;
	while (ret[i])
	{
		scores[i] = ret[i]->weight;
		ret[i]->weight = 0;
		i++;
	}
}

static int	get_nb_nodes(t_ind *lst)
{
	t_ind	*it;
	int		i;

	i = 0;
	it = lst;
	while (it && (++i))
		it = it->next;
	return (i);
}

static int	get_min_score(t_ind **ret, int *scores)
{
	int	i;
	int	min;

	i = -1;
	min = FT_INT_MAX;
	while (ret[++i])
		if (min > scores[i])
			min = scores[i];
	return (min);
}

static int	get_final_score(t_ind **ret, int *scores)
{
	int	i;
	int	min;

	i = -1;
	min = 0;
	while (ret[++i])
	{
		scores[i] = (ret[i]->weight > 0) * (get_nb_nodes(ret[i])
											+ ret[i]->weight - 1);
		if (min < scores[i])
			min = scores[i];
	}
	return (min);
}

int			get_score(t_lmdata *data, t_ind **ret, int nb_paths)
{
	int	nbants;
	int	i;
	int	min;
	int	scores[nb_paths];

	nbants = data->nbants;
	init_scores(ret, scores);
	min = get_min_score(ret, scores);
	while (nbants > 0 && (i = -1))
	{
		while (++i < nb_paths && nbants > 0)
			if (scores[i] == min)
			{
				nbants--;
				ret[i]->weight++;
				scores[i] = (ret[i]->weight > 0) * (get_nb_nodes(ret[i])
													+ ret[i]->weight - 1);
			}
		min = get_min_score(ret, scores);
	}
	return (get_final_score(ret, scores));
}
