/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:05:40 by mrojouan          #+#    #+#             */
/*   Updated: 2025/11/11 10:26:12 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	conversion(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	return (-1);
}

int	ft_atoi_base(char *str, int base)
{
	int multi = 1;
	int value = 0;
	int nbr = 0;
	int i = 0;

	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			multi = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') 
			|| (str[i] >= 'A' && str[i] <= 'F') 
				|| (str[i] >= 'a' && str[i] <= 'f'))
	{
		value = conversion(str[i]);
		if (value >= base)
			return (-1);
		nbr = nbr * base + value;
		i++;
	}
	return (nbr * multi);
} 