/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 21:09:18 by klebon            #+#    #+#             */
/*   Updated: 2019/03/07 22:18:05 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		check_type_one(const char **str, t_conv *field)
{
	if (**str == 'd' || **str == 'D' || **str == 'i' || **str == 'o'
		|| **str == 'u' || **str == 'x' || **str == 'X' || **str == 's'
		|| **str == 'S' || **str == 'c' || **str == 'C' || **str == 'U'
		|| **str == 'p' || **str == '%' || **str == 'O' || **str == 'f')
	{
		if (**str == 'd')
			field->fl_type = d;
		else if (**str == 'D')
			field->fl_type = D;
		else if (**str == 'i')
			field->fl_type = i;
		else if (**str == 'o')
			field->fl_type = o;
		else if (**str == 'u')
			field->fl_type = u;
		else if (**str == 'U')
			field->fl_type = U;
		else if (**str == 'x')
			field->fl_type = x;
		else if (**str == 'X')
			field->fl_type = X;
		return (1);
	}
	return (0);
}

ssize_t		check_type_two(const char **str, t_conv *field)
{
	if (**str == 'd' || **str == 'D' || **str == 'i' || **str == 'o'
		|| **str == 'u' || **str == 'x' || **str == 'X' || **str == 's'
		|| **str == 'S' || **str == 'c' || **str == 'C' || **str == 'U'
		|| **str == 'p' || **str == '%' || **str == 'O' || **str == 'f')
	{
		if (**str == 's')
			field->fl_type = s;
		else if (**str == 'S')
			field->fl_type = S;
		else if (**str == 'c')
			field->fl_type = c;
		else if (**str == 'C')
			field->fl_type = C;
		else if (**str == 'p')
			field->fl_type = p;
		else if (**str == '%')
			field->fl_type = percent;
		else if (**str == 'O')
			field->fl_type = O;
		else if (**str == 'f')
			field->fl_type = f;
		return (1);
	}
	return (0);
}
