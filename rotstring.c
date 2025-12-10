/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotstring.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:16:51 by mrojouan          #+#    #+#             */
/*   Updated: 2025/12/09 14:55:28 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_ws(char c)
{
	if ((c > 9 && c < 13) || c == ' ')
		return (1);
	return (0);
}

void ft_rotstring(char *str)
{
	int		i = 0;
	int		j;

	while (str[i] && is_ws(str[i]))
		i++;
	j = i;
	while (str[i])
	{
		while (str[i] && !is_ws(str[i]))
			i++;
		while (str[i] && is_ws(str[i]))
			i++;
		while (str[i] && (!is_ws(str[i]) && is_ws(str[i - 1])))
		{
			while (str[i] && !is_ws(str[i]))
			{
				write(1, &str[i], 1);
				i++; 
			}
			write(1, " ", 1);
			i++;
		}
	}
	while (str[j] && !is_ws(str[j]))
	{
		write(1, &str[j], 1);
		j++;
	}	
}
int main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	ft_rotstring(av[1]);
}