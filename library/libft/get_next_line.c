/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirzent <jpirzent@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 11:41:00 by jpirzent          #+#    #+#             */
/*   Updated: 2018/09/30 17:26:02 by jpirzent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* int		ft_newl(char **s, char **line, int fd, int b)
{
	int		len;
	char	*tmp;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
	{
		*line = ft_strsub(s[fd], 0, len);
		tmp = ft_strdup(s[fd] + len + 1);
		free(s[fd]);
		s[fd] = tmp;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else if(s[fd][len] == '\0')
	{
		if (b == BUFF_SIZE)
			return(get_next_line(fd, line));
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int			b;
	static char	*s[1];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((b = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[b] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (b < 0)
		return (-1);
	else if (b == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (ft_newl(s, line, fd, b));
} */
/*
** Note; this is a modified version of GNL (borrowed from Marco and called v4.0)
*/

static void		buffer_clean(char *buffer)
{
	int			i;
	int			j;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
	{
		i++;
		j = 0;
		while (buffer[i] && i > j)
		{
			buffer[j++] = buffer[i++];
		}
		buffer[j] = '\0';
	}
	else if (buffer[i] == '\0')
		ft_bzero(buffer, BUFF_SIZE + 1);
}

static int		newline_check(t_line *t, char *line[])
{
	char		*tmp;

	if (t->buffer[t->i] == '\n')
	{
		tmp = ft_strnjoin(*line, t->buffer, t->i);
		ft_strdel(line);
		*line = ft_strdup(tmp);
		ft_strdel(&tmp);
		buffer_clean(t->buffer);
		t->i = 0;
		return (1);
	}
	return (0);
}

static void		copy_to_line(t_line *t, char *line[])
{
	char		*tmp;

	tmp = ft_strnjoin(*line, t->buffer, t->i + 1);
	ft_strdel(line);
	*line = ft_strdup(tmp);
	ft_strdel(&tmp);
}

static int		return_check(int i, char *line)
{
	if (i < 0)
		return (-1);
	else if (i > 0)
	{
		return (1);
	}
	else if (i == 0 && *line)
	{
		return (1);
	}
	else if (line != NULL)
		ft_strdel(&line);
	return (0);
}

int				get_next_line(const int fd, char *line[])
{
	static		t_line t;

	if (fd < 0 || line == NULL || (*line = ft_strnew(0)) == NULL)
		return (-1);
	if (t.buffer[t.i])
	{
		while (t.buffer[t.i] && t.buffer[t.i] != '\n')
			t.i++;
		if (newline_check(&t, line))
			return (1);
		copy_to_line(&t, line);
	}
	while ((t.r = read(fd, t.buffer, BUFF_SIZE)) > 0)
	{
		t.buffer[t.r] = '\0';
		t.i = 0;
		while (t.buffer[t.i] && t.buffer[t.i] != '\n')
			t.i++;
		if (newline_check(&t, line))
			return (1);
		copy_to_line(&t, line);
	}
	return (return_check(t.r, *line));
}