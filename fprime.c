/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:01:40 by mrojouan          #+#    #+#             */
/*   Updated: 2025/12/02 16:08:13 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_fprime(int nbr)
{
	int i;

	i = 2;
	if (nbr == 1)
		printf("1");
	while (i <= nbr)
	{
		if (nbr % i == 0)
		{
			printf("%d", i);
			if (nbr != i)
				printf("*");
			nbr = nbr / i;
		}
		else
			i++;
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	ft_fprime(atoi(av[1]));
	write(1, "\n", 1);
}