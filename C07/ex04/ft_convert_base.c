/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfjeld <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 08:51:11 by rfjeld            #+#    #+#             */
/*   Updated: 2020/09/29 18:21:47 by rfjeld           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char			*atoi_escape(char *str, int *sign);

unsigned int	ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int				ft_check_base(char *base)
{
	unsigned int i;
	unsigned int j;

	if (ft_strlen(base) <= 1)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		if (base[i] <= 32 && base[i] >= 127)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int				ft_atoi_base(char *str, char *base)
{
	int				sign;
	int				nb;
	unsigned int	i;

	if (!ft_check_base(base))
		return (0);
	str = atoi_escape(str, &sign);
	nb = 0;
	i = 0;
	while (*str && i < ft_strlen(base))
	{
		i = -1;
		while (++i < ft_strlen(base))
		{
			if (base[i] == *str)
			{
				nb *= ft_strlen(base);
				nb += i;
				break ;
			}
		}
		str++;
	}
	nb *= sign;
	return (nb);
}

char			*atoi_escape(char *str, int *sign)
{
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	*sign = 1;
	while ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
			*sign = *sign * -1;
		str++;
	}
	return (str);
}
