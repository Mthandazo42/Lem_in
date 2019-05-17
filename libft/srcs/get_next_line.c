/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 18:08:15 by tmaze             #+#    #+#             */
/*   Updated: 2019/03/16 15:53:27 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**get_buff(const int fd, t_list **lst)
{
	t_list *tmp;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->content_size == (size_t)fd)
			return ((char**)&tmp->content);
		tmp = tmp->next;
	}
	if ((tmp = ft_lstnew("\0", fd)) == NULL)
		return (NULL);
	ft_lstadd(lst, tmp);
	return (get_buff(fd, lst));
}

static char	*supercat(char **s1, char **s2)
{
	char	*tmp;

	if ((tmp = ft_strjoin(*s1, *s2)) == NULL)
		return (NULL);
	ft_strdel(s1);
	ft_strclr(*s2);
	*s1 = tmp;
	return (*s1);
}

static int	check_buff(char **buff, char **line)
{
	int	ret;

	ret = 1;
	if (buff != NULL && (*buff == NULL || ft_strlen(*buff) == 0))
		ret = 0;
	else if ((*line = ft_strdup(*buff)) == NULL)
		ret = -1;
	ft_strclr(*buff);
	return (ret);
}

static int	read_gnl(const int fd, char **buff, char **line)
{
	char	*tmp;
	int		ret;

	if ((tmp = ft_strnew(BUFF_SIZE)) == NULL)
		return (-1);
	while (ft_strrnchr(*buff, '\n', BUFF_SIZE) == NULL
			&& (ret = read(fd, tmp, BUFF_SIZE)) > 0)
		if (supercat(buff, &tmp) == NULL)
		{
			ft_strdel(&tmp);
			return (-1);
		}
	ft_strdel(&tmp);
	if (buff != NULL && *buff != NULL
		&& ft_strrnchr(*buff, '\n', BUFF_SIZE) != NULL)
		return (get_next_line(fd, line));
	else
		return (check_buff(buff, line));
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*lst = NULL;
	char			**buff;
	char			*tmp;

	tmp = NULL;
	if (fd < 0 || read(fd, tmp, 0) == -1 || line == NULL)
		return (-1);
	if ((buff = get_buff(fd, &lst)) == NULL)
		return (-1);
	tmp = ft_strchr(*buff, '\n');
	if (tmp != NULL)
	{
		*line = ft_strndup(*buff, tmp - *buff);
		ft_memmove(*buff, &tmp[1], ft_strlen(&tmp[1]) + 1);
		return (1);
	}
	return (read_gnl(fd, buff, line));
}
