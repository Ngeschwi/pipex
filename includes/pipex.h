/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:05:15 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/09/14 17:43:59 by ngeschwi         ###   ########.fr       */
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

# define EXIT 0
# define ERROR 0
# define NO_ERROR 1

typedef struct s_data
{
	pid_t	pid;
	int		pipe_fd[2];
	int		fd_in;
	int		fd_out;
	char	*infile;
	char	*outfile;
	char	**new_argv1;
	char	**new_argv2;
	char	*path_arg1;
	char	*path_arg2;
	char	*all_path[7];
}				t_data;

int		ft_init_struct(t_data *data, char **argv);
int		ft_start(t_data *data, char **env);

int		ft_strlen(const char *str);
char	*ft_strdup(char *src);
char	*ft_strjoin(char *str, char *str2);
char	**ft_split(char const *s, char c);

#endif
