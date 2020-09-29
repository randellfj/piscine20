/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfjeld <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 14:40:47 by rfjeld            #+#    #+#             */
/*   Updated: 2020/09/27 20:11:31 by rfjeld           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

char	*ft_malloc(int size, char **strs, char *sep)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = j + ft_strlen(strs[i]);
		i++;
	}
	j = j + ft_strlen(sep) * (size - 1);
	if (size <= 0)
		j = 1;
	if (!(dest = malloc(sizeof(*dest) * j + 1)))
		dest = NULL;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	dest = ft_malloc(size, strs, sep);
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			dest[k++] = strs[i][j++];
		j = 0;
		while (sep[j] && i < (size - 1))
		{
			dest[k] = sep[j];
			j++;
			k++;
		}
		i++;
	}
	dest[k] = '\0';
	return (dest);
}
