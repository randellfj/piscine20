/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfjeld <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 21:53:56 by rfjeld            #+#    #+#             */
/*   Updated: 2020/09/22 11:35:18 by rfjeld           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int i;
	int result;

	result = nb;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	i = (power - 1);
	while (i--)
	{
		result *= nb;
	}
	return (result);
}
