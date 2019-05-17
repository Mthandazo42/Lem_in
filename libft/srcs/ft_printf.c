/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 22:27:58 by klebon            #+#    #+#             */
/*   Updated: 2019/03/07 22:16:43 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init_handler_tab(char *(*t[16])(t_conv *, va_list))
{
	t[d] = &handle_output_i_d;
	t[D] = &handle_output_i_d;
	t[i] = &handle_output_i_d;
	t[x] = &handle_output_hexa;
	t[X] = &handle_output_hexa;
	t[p] = &handle_output_hexa;
	t[o] = &handle_output_oct;
	t[O] = &handle_output_oct;
	t[u] = handle_output_u;
	t[U] = handle_output_u;
	t[c] = &handle_output_char;
	t[C] = &handle_output_wchar;
	t[s] = &handle_output_str;
	t[S] = &handle_output_wstr;
	t[percent] = &handle_output_char;
	t[f] = &handle_output_float;
}

void	clean_mem(t_conv *field, va_list ap)
{
	free(field);
	va_end(ap);
}

int		handle_conv(const char **str, t_conv *field, va_list ap, int *nb_print)
{
	char		*(*handler[16])(t_conv *, va_list);

	init_handler_tab(handler);
	(*str)++;
	if (check_fields(str, ap, field))
	{
		if (!(field->str = handler[field->fl_type](field, ap)))
		{
			clean_mem(field, ap);
			return (0);
		}
		write(1, field->str, field->str_size);
		*nb_print += field->str_size;
		free(field->str);
	}
	else
	{
		clean_mem(field, ap);
		return (0);
	}
	return (1);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	const char	*str;
	int			nb_print_chars;
	t_conv		*field;

	if (!(field = (t_conv *)malloc(sizeof(t_conv))))
		return (-1);
	va_start(ap, format);
	str = format;
	nb_print_chars = 0;
	while (str && *str)
	{
		if (*str != '%')
		{
			write(1, str, 1);
			++nb_print_chars;
		}
		else if (!(handle_conv(&str, field, ap, &nb_print_chars)))
			return (-1);
		++str;
	}
	clean_mem(field, ap);
	return (nb_print_chars);
}
