/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_text_file1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@stutent.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 11:46:03 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/07/08 11:46:03 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_get_text_file1(t_data *data)
{
	int	fd;
	int	get;

	fd = open(data->name_file1, O_RDONLY);
	get = get_next_line(fd, data);
	return (get);
}
