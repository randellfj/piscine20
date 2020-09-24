put/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfjeld <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:21:48 by rfjeld            #+#    #+#             */
/*   Updated: 2020/09/11 10:21:56 by rfjeld           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_char(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long n;

	n = nb;
	if (n < 0)
	{
		ft_print_char('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
	}
	ft_print_char(n % 10 + '0');
}
