/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfjeld <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 21:53:02 by rfjeld            #+#    #+#             */
/*   Updated: 2020/09/16 22:17:23 by rfjeld           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int a;
	unsigned int b;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dest[i])
		i++;
	a = 0;
	b = i;
	while (src[a] && a + i < size - 1)
	{
		dest[i + a] = src[a];
		a++;
	}
	if (a < size)
		dest[i + a] = '\0';
	if (size < b)
		return (ft_strlen(src) + size);
	return (b + ft_strlen(src));
}
