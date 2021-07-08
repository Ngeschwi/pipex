/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@stutent.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 13:11:33 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/07/08 12:29:41 by ngeschwi         ###   ########.fr       */
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
# define EXIT 0
# define ERROR 0
# define NO_ERROR 1

typedef struct	s_data
{
	char	*name_file1;
	char	*name_file2;
	char	*cmd1;
	char	*cmd2;
	char	*text_file1;
	char	*text_file2;
}				t_data;

void	ft_init_struct(t_data *data, char **argv);
int		ft_get_text_file1(t_data *data);
int		get_next_line(int fd, t_data *data);
int		ft_start(t_data *data, int *pipe_fd, char **env);

int		ft_strlen(const char *str);
char	*ft_strdup(char *src);
char	*ft_strjoin(char *str, char *str2);

#endif