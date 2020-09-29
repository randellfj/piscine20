/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfjeld <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:00:18 by rfjeld            #+#    #+#             */
/*   Updated: 2020/09/29 18:41:36 by rfjeld           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_separator(char *str, char *charset)
{
	while (*charset)
		if (*str == *charset++)
			return (1);
	return (0);
}

int			ft_strlen(char *str, char *charset)
{
	int i;

	i = 0;
	while (str[i] && !ft_separator(str + i, charset))
		i++;
	return (i);
}

int			ft_strcount(char *str, char *charset)
{
	int i;
	int j;

	j = 0;
	while (*str)
	{
		while (*str && ft_separator(str, charset))
			str++;
		i = ft_strlen(str, charset);
		str += i;
		if (i)
			j++;
	}
	return (j);
}

char		*ft_strcpy(char *src, int n)
{
	char *dest;

	if (!(dest = malloc((n + 1) * sizeof(char))))
		return (NULL);
	dest[n] = '\0';
	while (n--)
		dest[n] = src[n];
	return (dest);
}

char		**ft_split(char *str, char *charset)
{
	char	**tab;
	int		count;
	int		i;
	int		n;

	count = ft_strcount(str, charset);
	if (!(tab = malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	i = -1;
	while (++i < count)
	{
		while (*str && ft_separator(str, charset))
			str++;
		n = ft_strlen(str, charset);
		if (!(tab[i] = ft_strcpy(str, n)))
			return (NULL);
		str += n;
	}
	tab[count] = 0;
	return (tab);
}
int		main(void)
{
char **test;
	int i;

	i = 0;
	test = ft_split("Hey ahah, bon au taff camarades !", "abc");
	while(test[i])
	{
		printf("%s\n", test[i]);
		i++;
	}
	return (0);
}
