/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:04:20 by mrojouan          #+#    #+#             */
/*   Updated: 2025/12/09 16:10:57 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}
int is_ws(char c)
{
	if ((c > 9 && c < 13) || c == ' ')
		return (1);
	return (0);
}
void last_word(char *str)
{
	int len = ft_strlen(str);

	while (len >= 0 && is_ws(str[len]))
		len--;
	while (len >= 0 && !is_ws(str[len]))
		len--;
	len++;
	while (str[len] && !is_ws(str[len]))
	{
		write(1, &str[len], 1);
		len++;
	}
}
int main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	last_word(av[1]);
	write(1, "\n", 1);
}