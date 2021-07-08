/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@stutent.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:09:03 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/07/08 12:09:03 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char *str, char *str2)
{
	int		len_str;
	int		len_str2;
	int		i;
	char	*dst;

	i = -1;
	if (!str)
		return (ft_strdup(str2));
	len_str = ft_strlen(str);
	len_str2 = ft_strlen(str2);
	dst = malloc(sizeof(char) * (len_str + len_str2 + 1));
	if (!dst)
		return (NULL);
	while (++i < len_str)
		dst[i] = str[i];
	i = 0;
	while (i < len_str2)
	{
		dst[i + len_str] = str2[i];
		i++;
	}
	dst[i + len_str] = '\0';
	return (dst);
}
