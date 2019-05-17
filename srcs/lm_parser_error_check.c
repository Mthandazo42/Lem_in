/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_parser_error_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndhlovu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 06:42:37 by mndhlovu          #+#    #+#             */
/*   Updated: 2019/05/06 07:24:46 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int				lm_chk_format_nbr(char *raw)
{
	while (*raw)
	{
		if (*raw == '-' || *raw == '+')
			raw++;
		if (!ft_isdigit(*raw))
			return (-1);
		raw++;
	}
	return (0);
}

static int				lm_check_max(char *raw)
{
	if (ft_atoi(raw) < INT_MIN || ft_atoi(raw) > INT_MAX)
		return (-1);
	return (0);
}

static int				lm_validate_name(char *name)
{
	int					index;

	index = 0;
	if (name[0] == 'L')
		return (-1);
	while (name[index])
	{
		if (name[index] == '-')
			return (-1);
		index++;
	}
	return (0);
}

int						lm_validate_rooms(char *name, char *x, char *y)
{
	if (lm_validate_name(name) == -1)
		return (0);
	if (lm_chk_format_nbr(x) == -1
			|| lm_check_max(x) == -1
			|| (ft_atoi(x) > 0 && (ft_atoi(x) == 0))
			|| ft_strlen(x) > 19)
		return (0);
	if (lm_chk_format_nbr(y) == -1
			|| lm_check_max(y) == -1
			|| (ft_atoi(y) > 0 && (ft_atoi(y) == 0))
			|| ft_strlen(y) > 19)
		return (0);
	return (1);
}

int						lm_error_nbr(char *raw)
{
	if (lm_chk_format_nbr(raw) == -1
			|| lm_check_max(raw) == -1
			|| (ft_atoi(raw) > 0 && (ft_atoi(raw) == 0))
			|| ft_strlen(raw) > 19)
		return (0);
	return (1);
}
