/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_initdata.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 17:43:34 by tmaze             #+#    #+#             */
/*   Updated: 2019/05/09 17:35:50 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			lm_initdata(t_lmdata *data)
{
	data->nbants = 0;
	data->nodes_data = NULL;
	data->adj = NULL;
}

void			lm_check_start_vert(int count, t_holder *hol
				, t_lmdata *ldata, char *line)
{
	if ((hol->s_pos < hol->e_pos)
			&& lm_check_forbiden_chars(line, 0))
	{
		if ((count > hol->s_pos && count < hol->e_pos)
				&& (!hol->s_vert))
		{
			if ((lm_add_vertex(ldata, line, 's', hol)))
				hol->s_vert = count;
			else
				hol->s_error = 1;
		}
	}
	if ((hol->s_pos > hol->e_pos)
			&& lm_check_forbiden_chars(line, 0))
	{
		if (!hol->s_vert)
		{
			if ((lm_add_vertex(ldata, line, 's', hol)))
				hol->s_vert = count;
			else
				hol->s_error = 1;
		}
	}
}

void			lm_check_end_vert(int count, t_holder *hol
				, t_lmdata *ldata, char *line)
{
	if ((hol->e_pos < hol->s_pos)
			&& lm_check_forbiden_chars(line, 0))
	{
		if ((count > hol->e_pos && count < hol->s_pos)
				&& (!hol->e_vert))
		{
			if ((lm_add_vertex(ldata, line, 'e', hol)))
				hol->e_vert = count;
			else
				hol->e_error = 1;
		}
	}
	if ((hol->e_pos > hol->s_pos)
			&& lm_check_forbiden_chars(line, 0))
	{
		if (!hol->e_vert)
		{
			if ((lm_add_vertex(ldata, line, 'e', hol)))
				hol->e_vert = count;
			else
				hol->e_error = 1;
		}
	}
}

int				lm_init_src_dest(int *src, int *dest, t_lmdata *data
				, char *raw)
{
	int			s;
	int			d;
	char		**tab;

	if (raw != NULL)
	{
		tab = ft_strsplit(raw, '-');
		if (tab != NULL)
		{
			s = lm_find_index(data, tab[0]);
			d = lm_find_index(data, tab[1]);
			if (s == -1 || d == -1)
			{
				ft_del_words_tables(&tab);
				return (0);
			}
			*src = s;
			*dest = d;
			ft_del_words_tables(&tab);
			return (1);
		}
	}
	ft_del_words_tables(&tab);
	return (0);
}
