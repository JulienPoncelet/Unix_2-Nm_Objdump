/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 10:56:50 by jponcele          #+#    #+#             */
/*   Updated: 2014/03/26 18:05:58 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

static char				*strchr_gnl(const char *src, int *index)
{
	while (*index < BUFF_SIZE)
	{
		if (src[*index] == '\n')
			return ((char *)&src[*index + 1]);
		*index = *index + 1;
	}
	return (NULL);
}

static char				splitendl(char *buf, char **res, char **buf_tmp)
{
	int					i;
	char				*after;

	i = 0;
	after = strchr_gnl(buf, &i);
	*buf_tmp = ft_strnew(BUFF_SIZE + 1);
	if (after == NULL)
	{
		*res = ft_strjoin(*res, buf);
		*buf_tmp[0] = '\0';
		return ('0');
	}
	else
	{
		*res = ft_strjoin(*res, ft_strsub(buf, 0, i));
		*buf_tmp = after;
		return ('1');
	}
}

static ssize_t			ft_read(int fd, char *buf)
{
	ssize_t				ret;

	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	return (ret);
}

int						get_next_line(const int fd, char **line)
{
	static char			*buf = NULL;
	ssize_t				ret;
	char				stop;
	char				*buf_tmp;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (!buf)
		buf = ft_strnew(BUFF_SIZE + 1);
	*line = ft_strnew(1);
	stop = '0';
	ret = 1;
	while (ret > 0 && stop == '0')
	{
		if (buf[0] == '\0')
			ret = ft_read(fd, buf);
		stop = splitendl(buf, line, &buf_tmp);
		ft_memcpy(buf, buf_tmp, BUFF_SIZE);
	}
	if (ret > 0 || *line[0] != '\0')
		return (1);
	if (ret == 0)
		ft_strdel(&buf);
	return (ret);
}
