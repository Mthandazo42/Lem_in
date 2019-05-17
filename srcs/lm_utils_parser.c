/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_utils_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 09:24:45 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/05/09 17:40:24 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			lm_check_ant_no(char *line)
{
	int				len;

	len = ft_strlen(line);
	if (len > 0)
	{
		if (len == 1 && ft_isdigit(*line))
			return (*line - '0');
		else if (len > 1 && lm_error_nbr(line) && ft_isnumeric(line))
			return (ft_atoi(line));
	}
	return (0);
}

int					lm_get_value(char *line)
{
	if (line != NULL)
		return (lm_check_ant_no(line));
	return (0);
}

void				lm_get_cmd_vertices(int count, t_holder *holder
					, t_lmdata *ldata, char *line)
{
	if (count > 0 && line != NULL)
	{
		lm_check_start_vert(count, holder, ldata, line);
		lm_check_end_vert(count, holder, ldata, line);
	}
}

void				lm_get_vert_link(int count, t_lmdata *ldata
					, t_holder *holder, char *line)
{
	if (count > 0 && (count != holder->s_vert
				&& count != holder->e_vert)
			&& (count != holder->s_pos
				&& count != holder->e_pos && line != NULL))
	{
		if (lm_check_forbiden_chars(line, 0))
		{
			if (!(lm_add_vertex(ldata, line, 'v', holder)))
				holder->v_error = 1;
		}
		if (lm_check_forbiden_chars(line, 3))
		{
			if (!(lm_ext_conn(holder, ldata, line)))
				holder->l_error = 1;
		}
	}
}
