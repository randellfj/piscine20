/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfjeld <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:23:52 by rfjeld            #+#    #+#             */
/*   Updated: 2020/09/21 19:49:26 by rfjeld           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check_base(char *base)
{
	int i;
	int count;
	int j;

	count = 0;
	i = 0;
	while (base[i])
	{
		count = count + 1;
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i - 1;
		while (j > 0)
		{
			if (base[i] == base[j])
				return (0);
			--j;
		}
		i++;
	}
	if (count <= 1)
		return (0);
	return (count);
}

int		ft_result(char *str, char *base, int count, int i)
{
	int result;
	int j;

	result = 0;
	while (str[i])
	{
		j = 0;
		while (base[j])
		{
			if (str[i] == base[j])
			{
				result = result * count;
				result = result + j;
			}
			j++;
		}
		i++;
	}
	return (result);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int sign;
	int result;
	int count;

	i = 0;
	sign = 1;
	result = 0;
	count = (ft_check_base(base));
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = (-1) * sign;
		i++;
	}
	result = ft_result(str, base, count, i);
	result = (sign) * (result);
	return (result);
}
