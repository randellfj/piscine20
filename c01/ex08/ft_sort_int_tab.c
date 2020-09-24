/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfjeld <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 08:51:11 by rfjeld            #+#    #+#             */
/*   Updated: 2020/09/15 18:54:26 by rfjeld           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int term;

	term = *a;
	*a = *b;
	*b = *a;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[j] < tab[i])
			{
				ft_swap(tab + j, tab + i);
			}
			j++;
		}
		i++;
	}
}
