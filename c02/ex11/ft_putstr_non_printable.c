/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfjeld <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:21:29 by rfjeld            #+#    #+#             */
/*   Updated: 2020/09/15 18:53:13 by rfjeld           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_char(char c)
{
	write(1, &c, 1);
}

void	ft_print_hex(unsigned char c)
{
	char *base;

	base = "0123456789abcdef";
	ft_put_char('\\');
	ft_put_char(base[c / 16]);
	ft_put_char(base[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 127 && str[i] >= 32)
			ft_put_char(str[i]);
		else
			ft_print_hex(str[i]);
		i++;
	}
}
