/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_mem_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 06:31:37 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/05/09 17:33:39 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			lm_init_data(t_holder *holder, t_lmdata *ldata)
{
	holder->nb_state = 0;
	holder->s_cmd = 0;
	holder->e_cmd = 0;
	holder->s_error = 0;
	holder->e_error = 0;
	holder->v_error = 0;
	holder->l_error = 0;
	holder->s_vert = 0;
	holder->e_vert = 0;
	holder->state = 0;
	holder->s_pos = 0;
	holder->e_pos = 0;
	holder->v_flag = 0;
	holder->count = 0;
	holder->data = NULL;
	ldata->nbants = 0;
	ldata->nb_nodes = 0;
	ldata->nodes_data = NULL;
	ldata->adj = NULL;
	ldata->map = NULL;
}

static void		lm_add_vertex_sub(t_lmdata *ldata, t_node *new)
{
	t_node		*tmp;

	if (ldata->nodes_data == NULL)
		ldata->nodes_data = new;
	else
	{
		tmp = ldata->nodes_data;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	(ldata->nb_nodes)++;
}

int				lm_add_vertex(t_lmdata *ldata, char *raw, char flag,
				t_holder *holder)
{
	char		**tab;
	t_node		*new;
	char		*str;

	if (!(new = (t_node *)ft_memalloc(sizeof(t_node))))
		return (0);
	if ((tab = ft_strsplit(raw, ' ')) != NULL)
	{
		if (lm_check_room_before(tab, holder, &str))
		{
			new->name = str;
			new->x = ft_atoi(tab[1]);
			new->y = ft_atoi(tab[2]);
			new->role = flag;
			new->ind = ldata->nb_nodes;
			new->next = NULL;
			lm_add_vertex_sub(ldata, new);
			ft_del_words_tables(&tab);
			return (1);
		}
		ft_del_words_tables(&tab);
		free(new);
	}
	return (0);
}

int				lm_find_index(t_lmdata *data, char *str)
{
	t_node		*nodes;

	nodes = data->nodes_data;
	while (nodes)
	{
		if (ft_strequ(nodes->name, str))
			return (nodes->ind);
		nodes = nodes->next;
	}
	return (-1);
}

int				lm_ext_conn(t_holder *holder, t_lmdata *data, char *raw)
{
	t_temp		*new;
	int			src;
	int			dest;

	if (!(new = (t_temp *)ft_memalloc(sizeof(t_temp))))
		return (0);
	if (lm_init_src_dest(&src, &dest, data, raw))
	{
		new->src_ind = src;
		new->dest_ind = dest;
		new->next = NULL;
		if (holder->data == NULL)
			holder->data = new;
		else
			lm_ext_conn_sub(holder, new);
		(holder->count)++;
		holder->state = 1;
		return (1);
	}
	free(new);
	return (0);
}
