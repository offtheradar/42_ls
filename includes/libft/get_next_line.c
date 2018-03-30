/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 10:36:40 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/05 17:59:49 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		read_file(int fd, char **file_holder)
{
	char	*tmp;
	char	*tmp_fd;
	int		read_ret_val;

	tmp = ft_strnew(BUFF_SIZE);
	read_ret_val = 0;
	while ((read_ret_val = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		if (file_holder[fd])
		{
			tmp_fd = file_holder[fd];
			file_holder[fd] = ft_strjoin(file_holder[fd], tmp);
			free(tmp_fd);
		}
		else
			file_holder[fd] = ft_strdup(tmp);
		ft_strclr(tmp);
	}
	free(tmp);
	if (read_ret_val < 0)
		return (-1);
	return (0);
}

static int		fetch_next_line(char **file_holder, char **line)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if ((**file_holder) == '\0' || (*file_holder) == NULL)
		return (0);
	while ((*file_holder)[i] != '\n' && (*file_holder)[i])
		i++;
	*line = ft_strnew(i);
	ft_strncpy(*line, *file_holder, i);
	(*line)[i] = '\0';
	if ((*file_holder)[i] == '\n')
		i++;
	while ((*file_holder)[i])
		(*file_holder)[j++] = (*file_holder)[i++];
	(*file_holder)[j] = '\0';
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*file_holder[MAX_FD];
	int			return_val;

	if (fd < 0 || !line || BUFF_SIZE < 0 ||
			(return_val = read_file(fd, file_holder) == -1))
		return (-1);
	if (fetch_next_line(&file_holder[fd], line) == 0)
		return (0);
	return (1);
}
