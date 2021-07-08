/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fork_pipe_execve.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@stutent.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 10:47:07 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/07/08 10:47:07 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	test(int *pipe_fd, char **argv, char **env)
{
	pid_t	pid = -1;
	int		status;
    char	buffer[1024];
    int		ret;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		printf("je suis le fils et mon pid par rapport a mon pere est %d\n", pid);
		printf("je suis le fils est mon pid est %d\n", getpid());
		close(pipe_fd[0]);
		if (dup2(pipe_fd[1], 1) == -1)
			perror("dup2");
		else if (execve(argv[1], argv + 1, env) == -1)
			perror("execve");
	}
	else
	{
		wait(&status);
		printf("je suis le pere est mon pid est %d\n", getpid());
		printf("je suis le pere est le pid de mon fils est %d\n", pid);
		close(pipe_fd[1]);
		while ((ret = read(pipe_fd[0], buffer, 1023)) != 0)
		{
			buffer[ret] = 0;
			printf("la sortie de mon pipe est %s", buffer);
		}
	}
}

int	main(int argc, char **argv, char **env)
{
	int		pipe_fd[2];

	if (argc > 1)
	{
		if (pipe(pipe_fd) == -1)
		{
			perror("pipe");
			return (0);
		}
		test(pipe_fd, argv, env);
	}
	return (0);
}
