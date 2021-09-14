/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:01:20 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/09/14 16:14:25 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_fils(t_data *data, char **env)
{
	if (dup2(data->fd_in, 0) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	if (dup2(data->pipe_fd[1], 1) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(data->pipe_fd[0]);
	if (execve(data->path_arg1, data->new_argv1, env) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
	return (ERROR);
}

static int	ft_pere(t_data *data, char **env)
{
	wait(NULL);
	if (dup2(data->pipe_fd[0], 0) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	if (dup2(data->fd_out, 1) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(data->pipe_fd[1]);
	if (execve(data->path_arg2, data->new_argv2, env) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
	return (ERROR);
}

int	ft_start(t_data *data, char **env)
{
	if (pipe(data->pipe_fd) == -1)
	{
		perror("pipe");
		return (0);
	}
	data->pid = fork();
	if (data->pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (data->pid == 0)
	{
		if (ft_fils(data, env) == ERROR)
			return (ERROR);
	}
	else
	{
		if (ft_pere(data, env) == ERROR)
			return (ERROR);
	}
	return (NO_ERROR);
}
