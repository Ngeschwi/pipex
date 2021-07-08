/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@stutent.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 11:39:10 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/07/08 11:39:10 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_strjoin_gnl(char **str, char *buff)
{
	int		len_str;
	int		len_buff;
	int		i;
	char	*dst;

	i = -1;
	if (!(*str))
		return (ft_strdup(buff));
	len_str = ft_strlen(*str);
	len_buff = ft_strlen(buff);
	dst = malloc(sizeof(char) * (len_str + len_buff + 1));
	if (!dst)
		return (NULL);
	while (++i < len_str)
		dst[i] = (*str)[i];
	i = 0;
	while (i < len_buff)
	{
		dst[i + len_str] = buff[i];
		i++;
	}
	dst[i + len_str] = '\0';
	free(*str);
	return (dst);
}

int	get_next_line(int fd, t_data *data)
{
	char	buff[BUFFER_SIZE + 1];
	char	*str;
	int		nbr_read;

	if (BUFFER_SIZE <= 0 || !data->text_file1 || fd < 0 || read(fd, buff, 0) < 0)
		return (ERROR);
	str = NULL;
	nbr_read = read(fd, buff, BUFFER_SIZE);
	while (nbr_read > 0)
	{
		buff[nbr_read] = '\0';
		str = ft_strjoin_gnl(&str, buff);
		nbr_read = read(fd, buff, BUFFER_SIZE);
	}
	data->text_file1 = ft_strdup(str);
	free(str);
	return (NO_ERROR);
}
