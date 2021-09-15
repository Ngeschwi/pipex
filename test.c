/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 08:46:45 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/09/15 11:21:29 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

int	test(int *pipe_fd, int *pipe_fd2, int fd_out, int fd_in, char **argv, char **env)
{
	pid_t	pid = -1;
	char	*cpy_argv[3];
	char	*cpy_argv2[3];

	cpy_argv[0] = "ls";
	cpy_argv[1] = "-l";
	cpy_argv[2] = NULL;
	cpy_argv2[0] = "wc";
	cpy_argv2[1] = "-w";
	cpy_argv2[2] = NULL;
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		dup2(fd_in, 0);
		close(pipe_fd[0]);
		if (dup2(pipe_fd[1], 1) == -1)
			perror("dup2");
		close(pipe_fd[1]);
		if (execve("/bin/ls", cpy_argv, env) == -1)
			perror("execve");
	}
	else
	{
		wait(NULL);
		dup2(pipe_fd[0], 0);
		dup2(fd_out, 1);
		close(pipe_fd[1]);
		if (execve("/usr/bin/wc", cpy_argv2, env) == -1)
			perror("execve");
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	int	pipe_fd[2];
	int	pipe_fd2[2];
	int	fd_out;
	int	fd_in;

	if (argc == 1)
	{
		if (pipe(pipe_fd) == -1)
		{
			perror("pipe");
			return (0);
		}
		fd_out = open("outfile", O_CREAT, S_IRWXU);
		fd_out = open("outfile", O_RDWR);
		fd_in = open("infile", O_RDWR);
		test(pipe_fd, pipe_fd2, fd_out, fd_in, argv, env);
	}
	return (0);
}
