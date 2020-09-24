/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfjeld <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 10:06:05 by rfjeld            #+#    #+#             */
/*   Updated: 2020/09/15 15:43:14 by rfjeld           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_strlowcse(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	ft_strlowcse(str);
	while (str[i])
	{
		if (!(str[i] >= 'a' && str[i] <= 'z') &&
			!(str[i] >= 'A' && str[i] <= 'Z') &&
			!(str[i] >= '0' && str[i] <= '9'))
		{
			if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
			{
				str[i + 1] -= 32;
			}
		}
		else if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
