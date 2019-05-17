/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 06:31:05 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/05/09 17:38:50 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		start_end_link(t_lmdata *data, int s_ind, int e_ind)
{
	t_ind	*it;

	it = data->adj[s_ind];
	while (it)
	{
		if (it->index == e_ind)
			return (1);
		it = it->next;
	}
	return (0);
}

static int		do_algorithm(t_lmdata *lmdata, t_ind ***ret)
{
	get_nb_paths_max(lmdata, get_node_role(lmdata, 's')->ind
					, get_node_role(lmdata, 'e')->ind);
	if ((*ret = edmonds_karp(lmdata, get_node_role(lmdata, 's')->ind
							, get_node_role(lmdata, 'e')->ind)) == NULL)
		return (0);
	print_map(lmdata);
	if (!push_ants(lmdata, *ret, get_nb_paths(*ret)))
		return (0);
	tablst_inddel(*ret);
	return (1);
}

static int		lem_in(t_holder *holder,
					t_lmdata *lmdata, t_ind ***ret)
{
	lm_parser(lmdata, holder);
	if (!lm_verify_cmd(holder, lmdata))
		return (0);
	if (!lst_indinit(lmdata))
		return (0);
	if ((lm_adj_parser(lmdata, holder) == 0))
		return (0);
	lm_clear_unv(holder);
	if (start_end_link(lmdata, get_node_role(lmdata, 's')->ind
						, get_node_role(lmdata, 'e')->ind))
	{
		print_map(lmdata);
		push_ants_end(lmdata, get_node_role(lmdata, 'e')->name);
	}
	else if (!do_algorithm(lmdata, ret))
		return (0);
	del_map(lmdata);
	return (1);
}

static int		lm_error_exit(void)
{
	ft_putendl_fd("ERROR", 2);
	return (1);
}

int				main(int ac, char **av)
{
	t_lmdata	ldata;
	t_holder	holder;
	t_ind		**ret;

	(void)av;
	if (ac == 1)
	{
		lm_init_data(&holder, &ldata);
		if (!(lem_in(&holder, &ldata, &ret)))
		{
			lm_clean_data(&ldata);
			del_map(&ldata);
			return (lm_error_exit());
		}
		del_map(&ldata);
		lm_clean_data(&ldata);
		return (0);
	}
	return (1);
}
