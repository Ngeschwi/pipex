/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 13:11:33 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/09/13 17:17:41 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>

# define BUFFER_SIZE 50
# define STD_IN 0
# define STD_OUT 1
# define EXIT 0
# define ERROR 0
# define NO_ERROR 1

typedef struct	s_data
{
	int		pipe_fd[2];
	int		fd_in;
	int		fd_out;
	char	*new_argv1[3];
	char	*new_argv2[3];
	char	*infile;
	char	*outfile;
}				t_data;

int		ft_strlen(const char *str);
char	*ft_strdup(char *src);
char	*ft_strjoin(char *str, char *str2);

int		ft_init_struct(t_data *data, char **argv);

#endif