/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@stutent.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 11:58:59 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/07/08 11:58:59 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(char *src)
{
	char	*copy;
	int		size_src;
	int		i;

	i = 0;
	size_src = ft_strlen(src);
	copy = malloc(sizeof(char) * (size_src + 1));
	if (copy == NULL)
		return (NULL);
	if (size_src == 0)
	{
		copy[0] = '\0';
		return (copy);
	}
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	if (size_src != 0)
		copy[i] = '\0';
	return (copy);
}
