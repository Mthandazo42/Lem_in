/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 14:42:35 by tmaze             #+#    #+#             */
/*   Updated: 2019/01/29 18:16:22 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tabtopath(char **tab_path)
{
	size_t	total_size;
	size_t	i;
	char	*ret;

	i = 0;
	total_size = 0;
	while (tab_path[i])
		total_size += ft_strlen(tab_path[i++]);
	total_size = (total_size == 0) ? 1 : total_size;
	if ((ret = ft_strnew(total_size + i)) == NULL)
		return (NULL);
	i = 0;
	ft_strcat(ret, "/");
	while (tab_path[i])
	{
		if (i > 0)
			ft_strcat(ret, "/");
		ft_strcat(ret, tab_path[i++]);
	}
	return (ret);
}

void	ft_reducepath(char ***tab)
{
	size_t	i;
	size_t	j;
	int		strcmp;

	i = 0;
	while ((*tab)[i])
	{
		if ((strcmp = ft_strcmp((*tab)[i], "..")) == 0
			|| ft_strcmp((*tab)[i], ".") == 0)
		{
			ft_strdel(&((*tab)[i]));
			if ((j = i) == i && strcmp == 0 && i != 0)
				ft_strdel(&((*tab)[i - 1]));
			while ((*tab)[++j])
				(*tab)[j - ((strcmp == 0 && i != 0) ? 2 : 1)] = (*tab)[j];
			if (strcmp == 0 && i != 0)
				(*tab)[j - 2] = NULL;
			(*tab)[j - 1] = NULL;
			if (strcmp == 0 && i != 0)
				i--;
		}
		else
			i++;
	}
}

char	*ft_realpath(char *r_path, char **a_path)
{
	char	**tab_path;

	if ((tab_path = ft_strsplit(r_path, '/')) == NULL)
		return (NULL);
	ft_reducepath(&tab_path);
	*a_path = ft_tabtopath(tab_path);
	ft_del_words_tables(&tab_path);
	return (*a_path);
}
