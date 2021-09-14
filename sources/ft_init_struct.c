/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:05:04 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/09/14 18:05:54 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_get_path(t_data *data, char	**argv)
{
	int		i;
	int		check;
	char	*save;

	i = 0;
	check = 0;
	while (i < 8 && check == 0)
	{
		save = ft_strjoin(data->all_path[i], argv[0]);
		if (access(save, X_OK) == 0)
		{
			check++;
			return (save);
		}
		free(save);
		i++;
	}
	return (NULL);
}

static int	ft_get_argv(t_data *data, char **argv)
{
	data->pid = -1;
	data->infile = argv[1];
	data->outfile = argv[4];
	data->fd_in = open(data->infile, O_RDWR);
	data->fd_out = open(data->outfile, O_CREAT, S_IRWXU);
	data->fd_out = open(data->outfile, O_RDWR);
	if (data->fd_in == -1)
	{
		write(data->fd_out, "	   0", 5);
		perror("fd infile");
		return (ERROR);
	}
	if (data->fd_out == -1)
	{
		perror("erreur outfile");
		return (ERROR);
	}
	data->new_argv1 = ft_split(argv[2], ' ');
	data->new_argv2 = ft_split(argv[3], ' ');
	data->path_arg1 = ft_get_path(data, data->new_argv1);
	data->path_arg2 = ft_get_path(data, data->new_argv2);
	return (NO_ERROR);
}

int	ft_init_struct(t_data *data, char **argv)
{
	if (pipe(data->pipe_fd) == -1)
	{
		perror("Pipe");
		return (ERROR);
	}
	data->all_path[0] = "/usr/local/bin/";
	data->all_path[1] = "/usr/bin/";
	data->all_path[2] = "/bin/";
	data->all_path[3] = "/usr/sbin/";
	data->all_path[4] = "sbin/";
	data->all_path[5] = "/usr/local/munki/";
	data->all_path[6] = "/opt/X11/bin/";
	if (ft_get_argv(data, argv) == ERROR)
		return (ERROR);
	return (NO_ERROR);
}
