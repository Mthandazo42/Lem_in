/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 15:24:51 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/05/09 16:55:53 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		lm_locate_cd(int index, t_holder *holder, char *line)
{
	char		*tmp;

	tmp = ft_strchr(line, '#');
	if ((!holder->s_cmd || !holder->e_cmd)
			&& (tmp != NULL && line[1] == '#'
				&& lm_check_forbiden_chars(line, 1)))
	{
		if (!holder->s_cmd)
		{
			if (ft_strcmp(line, "##start") == 0)
			{
				holder->s_cmd = 1;
				holder->s_pos = index;
			}
		}
		if (!holder->e_cmd)
		{
			if (ft_strcmp(line, "##end") == 0)
			{
				holder->e_cmd = 1;
				holder->e_pos = index;
			}
		}
	}
}

static int		lm_get_ant_(int counter, t_lmdata *ldata
				, t_holder *holder, char *line)
{
	int			value;

	if (counter == 0 && lm_check_forbiden_chars(line, 0))
	{
		value = lm_get_value(line);
		if (value > 0)
		{
			ldata->nbants = value;
			holder->nb_state = 1;
			return (1);
		}
	}
	return (0);
}

static int		lm_get_vertices(int count, t_lmdata *data
				, t_holder *holder, char *line)
{
	lm_get_cmd_vertices(count, holder, data, line);
	if (!holder->s_error && !holder->e_error)
	{
		lm_get_vert_link(count, data, holder, line);
		if (!holder->v_error && !holder->l_error)
			return (1);
	}
	return (0);
}

int				lm_parser(t_lmdata *ldata, t_holder *holder)
{
	char		*raw;
	int			index;

	index = 0;
	while (ft_getline(&raw) > 0 && raw[0] != '\0')
	{
		if ((add_line_map(ldata, raw)))
			return (0);
		if (!(lm_get_ant_(index, ldata, holder, raw)) && index == 0)
			return (0);
		lm_locate_cd(index, holder, raw);
		if (!(lm_get_vertices(index, ldata, holder, raw)))
			return (0);
		index++;
	}
	ft_strdel(&raw);
	return (1);
}
