/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 17:54:29 by tmaze             #+#    #+#             */
/*   Updated: 2018/04/15 15:55:03 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int		i;
	int		nb_words;
	int		in_word;

	in_word = 0;
	nb_words = 0;
	i = -1;
	while (++i == 0 || s[i - 1])
		if (!in_word && s[i] != c && s[i] != '\0')
		{
			in_word = 1;
			nb_words++;
		}
		else if (in_word && (s[i] == c || s[i] == '\0'))
			in_word = 0;
	return (nb_words);
}

static char	**get_table(char const *s, char c, char **tab)
{
	int		i;
	int		nb_words;
	int		in_word;
	size_t	start;

	nb_words = 0;
	in_word = 0;
	i = -1;
	while (++i == 0 || s[i - 1])
		if (!in_word && s[i] != c && (in_word = 1))
			start = i;
		else if (in_word && (s[i] == c || s[i] == '\0'))
		{
			if ((tab[nb_words] = ft_strsub(s, start, i - start)) == NULL)
			{
				while (--nb_words >= 0)
					ft_strdel(&tab[nb_words]);
				free(tab);
				return (NULL);
			}
			nb_words++;
			in_word = 0;
		}
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	int		nb_words;
	char	**tab;

	nb_words = 0;
	tab = NULL;
	if (s != NULL)
	{
		nb_words = count_words(s, c);
		if ((tab = (char**)malloc(sizeof(char**) * (nb_words + 1))) == NULL)
			return (NULL);
		tab[nb_words] = NULL;
		return (get_table(s, c, tab));
	}
	else
		return (NULL);
}
