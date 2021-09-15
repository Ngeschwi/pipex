/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@stutent.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 13:13:55 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/07/07 13:13:55 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if (argc == 5)
	{
		if (ft_init_struct(&data, argv) == ERROR)
			return (0);
		if (pipe(data.pipe_fd) == -1)
		{
			ft_free_data(&data);
			perror("Pipe");
			return (ERROR);
		}
		data.pid = fork();
		if (data.pid == -1)
		{
			ft_free_data(&data);
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (ft_start(&data, env) == ERROR)
			return (ERROR);
	}
	else
		perror("Erreur dans le nombre d'argument");
	return (0);
}
