/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_data_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 06:35:40 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/05/09 17:35:34 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_rdata				*lm_new_raw_line(char *raw)
{
	t_rdata			*line;

	if (!(line = (t_rdata *)malloc(sizeof(t_rdata))))
		return (NULL);
	line->line = ft_strdup(raw);
	line->next = NULL;
	return (line);
}

void				lm_append_line(t_rdata **line, char *raw)
{
	if (*line)
	{
		if ((*line)->next)
			lm_append_line(&(*line)->next, raw);
		else
			(*line)->next = lm_new_raw_line(raw);
	}
	else
		*line = lm_new_raw_line(raw);
}

void				lm_clean_data(t_lmdata *data)
{
	t_node			*tmp;
	int				i;

	while (data->nodes_data)
	{
		tmp = data->nodes_data;
		data->nodes_data = data->nodes_data->next;
		ft_strdel(&(tmp->name));
		ft_memdel((void**)&tmp);
	}
	i = 0;
	while (i < data->nb_nodes)
	{
		if (data->adj && data->adj[i])
			lst_inddel(&(data->adj[i]));
		i++;
	}
	ft_memdel((void**)&(data->adj));
}
