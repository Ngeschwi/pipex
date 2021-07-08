/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@stutent.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 11:02:43 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/07/08 11:02:43 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init_struct(t_data *data, char **argv)
{
	data->name_file1 = argv[1];
	data->cmd1 = ft_strjoin("/bin/", argv[2]);
	data->cmd2 = ft_strjoin("/bin/", argv[3]);
	data->name_file2 = argv[4];
	data->text_file1 = NULL;
	data->text_file2 = NULL;
}
