/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools_float.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:52:34 by tmaze             #+#    #+#             */
/*   Updated: 2019/03/07 22:23:31 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		roundup(char *str, long double n, int i, int prec)
{
	int	ret;
	int	len;

	ret = 1;
	len = ft_strlen(str);
	if ((int)n >= 5 && (n - (int)n) > 0.0)
	{
		while (i-- != 0 && ret == 1)
		{
			if (str[i] != '.' && str[i] + 1 > '9' && (ret = 1))
				str[i] = '0';
			else if (str[i] != '.' && !(ret = 0))
				str[i]++;
		}
		if (ret == 1 && (i = ft_strlen(str)) < 4980)
			while (--i > 0)
				str[i + 1] = str[i];
		str[0] = (ret == 1 && i < 4980) ? '1' : str[0];
	}
	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	i += prec + 1;
	while (i < len)
		str[i++] = '\0';
}

void		getint(char *str, long double n, int *i)
{
	uint64_t	nb;
	long double	div;

	nb = n;
	div = 1;
	while ((nb / div) >= 10)
		div *= 10;
	nb /= div;
	while (*i < 4935 && div != 0)
	{
		str[*i] = (int)nb + '0';
		div = (div == 1) ? 0 : (div / 10);
		nb = dmod((n / div), 10);
		(*i)++;
	}
}

char		*getnbrstr(long double nb, t_conv *field)
{
	char		str[4980];
	int			i;
	int			j;

	ft_bzero(str, 4980);
	nb = nb * ((nb < 0.0) ? -1 : 1);
	i = 0;
	getint(str, nb, &i);
	j = 0;
	if (field->fl_prec > 0 || field->fl_hashtag)
		str[i++] = '.';
	nb = (nb - (uint64_t)nb) * ((nb < 0.0) ? -1 : 1) * 10;
	while (j < field->fl_prec && i + j < 4980)
	{
		str[i + j] = (uint64_t)nb + '0';
		nb = (nb - (uint64_t)nb) * 10;
		j++;
	}
	i += j;
	roundup(str, nb, i, field->fl_prec);
	return (ft_strdup(str));
}

void		set_strf(t_conv *f, char *nbrstr, long double nb, int pad)
{
	if (!f->fl_minus && !f->fl_zero)
		ft_memset(f->str, ' ', (pad > 0) ? pad : 0);
	if (nb < 0.0)
		f->str[ft_strlen(f->str)] = '-';
	else if (f->fl_plus || f->fl_space)
		f->str[ft_strlen(f->str)] = (f->fl_plus) ? '+' : ' ';
	if (!f->fl_minus && f->fl_zero)
		ft_memset(&f->str[ft_strlen(f->str)], '0', (pad > 0) ? pad : 0);
	ft_strcat(f->str, nbrstr);
	if (f->fl_minus)
		ft_memset(&f->str[ft_strlen(f->str)], ' ', (pad > 0) ? pad : 0);
}

char		*handle_output_float(t_conv *field, va_list ap)
{
	long double	nb;
	int			pad;
	int			size;
	char		*nbrstr;

	if (field->fl_size == L)
		nb = (long double)va_arg(ap, long double);
	else
		nb = (long double)va_arg(ap, double);
	field->fl_prec = (field->fl_prec == -1) ? 6 : field->fl_prec;
	nbrstr = getnbrstr(nb, field);
	size = set_malloc_sizef(nb, nbrstr, field);
	pad = field->str_size - size;
	if ((field->str = ft_strnew(field->str_size)) != NULL)
		set_strf(field, nbrstr, nb, pad);
	ft_strdel(&nbrstr);
	return (field->str);
}
