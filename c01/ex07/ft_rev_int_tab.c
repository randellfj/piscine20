/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfjeld <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 12:00:40 by rfjeld            #+#    #+#             */
/*   Updated: 2020/09/14 08:50:04 by rfjeld           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int term;

	term = *a;
	*a = *b;
	*b = term;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int term;

	if (size < 2)
		return ;
	term = 0;
	while (term < --size)
		ft_swap(&tab[term++], &tab[size]);
}
