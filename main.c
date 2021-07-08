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
	int		pipe_fd[2];

	if (argc != 5)
		return (EXIT);
	ft_init_struct(&data, argv);
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		return (ERROR);
	}
	if (ft_get_text_file1(&data) == ERROR)
		return (ERROR);
	ft_start(&data, pipe_fd, env);
}
