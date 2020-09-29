/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfjeld <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 08:50:56 by rfjeld            #+#    #+#             */
/*   Updated: 2020/09/29 18:21:50 by rfjeld           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				ft_atoi_base(char *str, char *base);
unsigned int	ft_strlen(char *str);
int				ft_check_base(char *base);

char			*ft_rev_int_tab(char *tab, int size)
{
	int		i;
	char	tmp;

	i = 0;
	if (size == 0)
		size++;
	while (i < size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = tmp;
		i++;
	}
	tab[size] = '\0';
	return (tab);
}

char			*ft_putnbr_base(int nb, char *base, char *tab)
{
	int				i;
	int				j;
	int				neg;
	unsigned int	nbr;

	neg = 1;
	j = 0;
	i = ft_strlen(base);
	nbr = nb;
	if (nb < 0)
	{
		neg = -1;
		nbr = -nb;
	}
	if (nbr == 0)
		tab[j] = base[nbr % i];
	while (nbr)
	{
		tab[j++] = base[nbr % i];
		nbr /= i;
	}
	if (neg < 0)
		tab[j++] = '-';
	return (ft_rev_int_tab(tab, j));
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		result_int;
	char	*result_str;

	result_str = malloc(20 * sizeof(char));
	if (ft_check_base(base_from) == 0)
		return (NULL);
	if (ft_check_base(base_to) == 0)
		return (NULL);
	else
	{
		result_int = ft_atoi_base(nbr, base_from);
		result_str = ft_putnbr_base(result_int, base_to, result_str);
	}
	return (result_str);
}
