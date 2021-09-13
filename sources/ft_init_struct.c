/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:05:04 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/09/13 17:39:11 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_get_argv(t_data *data, char **argv)
{
	data->infile = argv[1];
	data->outfile = argv[4];
	data->fd_in = open(data->infile, O_RDWR);
	data->fd_out = open(data->outfile, O_RDWR);
	printf("fd_in : %d\n", data->fd_in);
	printf("fd_out : %d\n", data->fd_out);
}

int	ft_init_struct(t_data *data, char **argv)
{
	if (pipe(data->pipe_fd) == -1)
	{
		perror("Pipe");
		return (ERROR);
	}
	ft_get_argv(data, argv);
	return (NO_ERROR);
}
