/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <mndhlovu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 08:55:30 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/05/09 17:37:23 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int					lm_check_room_before(char **tab, t_holder *holder
					, char **name)
{
	if (tab[0] != NULL && tab[1] != NULL && tab[2] != NULL)
	{
		if (lm_validate_rooms(tab[0], tab[1], tab[2]) && !holder->state)
		{
			if (!(*name = ft_strdup(tab[0])))
				return (0);
			return (1);
		}
	}
	holder->v_error = 1;
	return (0);
}

int					lm_check_forbiden_chars(char *line, int flag)
{
	char			*hash;
	char			*dash;

	if (line != NULL)
	{
		dash = ft_strchr(line, '-');
		hash = ft_strchr(line, '#');
		if (flag == 0 && dash == NULL && hash == NULL)
			return (1);
		if (flag == 1 && dash == NULL && hash != NULL)
			return (1);
		if (flag == 2 && dash == NULL
				&& (hash == NULL || (hash != NULL && line[1] != '#')))
			return (1);
		if (flag == 3 && (dash != NULL && hash == NULL))
			return (1);
	}
	return (0);
}

void				lm_clear_unv(t_holder *holder)
{
	t_temp			*data;
	t_temp			*flush;

	data = holder->data;
	while (data)
	{
		flush = data;
		data = data->next;
		free(flush);
		flush = NULL;
	}
	holder->data = NULL;
}

int					lm_verify_links(t_holder *data, t_holder *hold)
{
	if (!hold->l_error
	|| (hold->l_error
	&& data->count > 0))
		return (1);
	return (0);
}

int					lm_verify_cmd(t_holder *holder
						, t_lmdata *data)
{
	if (holder->s_cmd && holder->e_cmd
			&& !holder->e_error && !holder->s_error
			&& !holder->v_error
			&& holder->s_vert
			&& holder->e_vert
			&& holder->nb_state
			&& lm_verify_links(holder, holder)
			&& (data->nb_nodes > 0))
		return (1);
	lm_clear_unv(holder);
	return (0);
}
