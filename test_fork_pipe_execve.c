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

#include "includes/pipex.h"

int	test(int *pipe_fd, char **argv, char **env)
{
	pid_t	pid = -1;
	int		status;
    char	buffer[1024];
    int		ret;

	//on lance le fork puis on check s'il y a une erreur
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	// si le pid est egale a 0, alors nous sommes dans le processus du fils
	if (pid == 0)
	{
		// le pid du fils par rapport au pere est egale a 0 qui est la valuer de 'pid'
		printf("je suis le fils et mon pid par rapport a mon pere est %d\n", pid);
		// pour obtenir le vrqi pid du fils on utilise getpid()
		printf("je suis le fils est mon pid est %d\n", getpid());
		// on ferme l'entree standard de notre pipe avec close()
		close(pipe_fd[0]);
		// on change le fd 1, soit le terminal, la sortie standard, par la sortie de notre pipe, ainsi au lieu d'ecrire dans le terminal on pourra retrouver nos valeur de l'autre cote de notre pipe
		if (dup2(pipe_fd[1], 1) == -1)
			perror("dup2");
		// on execute la commande donnee en parametre, le resultat de cette commande sera ecrite a la sortie de notre pipe
		else if (execve(argv[1], argv + 1, env) == -1)
			perror("execve");
	}
	//on se trouve dans le processus du pere
	else
	{
		// on attend aque le processus du fils soit fini pour lancer celui du pere
		wait(&status);
		// pour avoir le pid du pere on utilise getpid()
		printf("je suis le pere est mon pid est %d\n", getpid());
		// pour avoir le pid du fils on utilise la variable 'pid'
		printf("je suis le pere est le pid de mon fils est %d\n", pid);
		// on ferme la sortie standard
		close(pipe_fd[1]);
		// on lit la commande envoyee dans le pipe precedemment puis on l'affiche
		while ((ret = read(pipe_fd[0], buffer, 1023)) != 0)
		{
			buffer[ret] = 0;
			printf("la sortie de mon pipe est :\n%s", buffer);
		}
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	// on initialise les valeurs pour le pipe, soit l'entree standard, la sortie standard et la srtie d'erreur
	int		pipe_fd[2];

	if (argc > 1)
	{
		//on initialise le pipe et on check s'il n'y a pas d'erreur
		if (pipe(pipe_fd) == -1)
		{
			perror("pipe");
			return (0);
		}
		test(pipe_fd, argv, env);
	}
	return (0);
}
