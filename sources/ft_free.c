/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:50:41 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/09/15 15:50:59 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_data(t_data *data)
{
	int	i;

	i = 0;
	free(data->path_arg1);
	free(data->path_arg2);
	while (data->new_argv1[i])
	{
		free(data->new_argv1[i]);
		i++;
	}
	i = 0;
	while (data->new_argv2[i])
	{
		free(data->new_argv2[i]);
		i++;
	}
	free(data->new_argv1);
	free(data->new_argv2);
}
