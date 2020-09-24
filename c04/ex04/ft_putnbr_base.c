/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfjeld <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 20:34:06 by rfjeld            #+#    #+#             */
/*   Updated: 2020/09/21 16:22:19 by rfjeld           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_char(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb, int count, char *base)
{
	long int n;

	n = nb;
	if (n < 0)
	{
		ft_print_char('-');
		n = -n;
	}
	if (n >= count)
	{
		ft_putnbr((n / count), count, base);
		ft_print_char(base[n % count]);
	}
	else
		ft_print_char(base[n % count]);
}

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

void	ft_putnbr_base(int nbr, char *base)
{
	int count;

	count = (ft_check_base(base));
	ft_putnbr(nbr, count, base);
}
