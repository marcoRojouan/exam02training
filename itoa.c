/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:35:48 by mrojouan          #+#    #+#             */
/*   Updated: 2025/12/08 14:11:26 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int nbr_len(int nbr)
{
	int count;

	count = 1;
	while (!(nbr < 10) || !(nbr > -10))
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*duplicata;
	int		i;
	int		len;

	len = ft_strlen(str);
	duplicata = NULL;
	duplicata = malloc(sizeof(char) * len + 1);
	if (!duplicata)
		return (0);
	i = 0;
	while (i < len)
	{
		duplicata[i] = str[i];
		i++;
	}
	duplicata[i] = '\0';
	return (duplicata);
}

char *ft_itoa(int nbr)
{
	char	*str_nbr;
	int		len;

	len = nbr_len(nbr);
	str_nbr = malloc(sizeof(char) * (len + 1));
	if (!str_nbr)
		return (NULL);
	if (nbr == -2147483648)
    {
    	str_nbr = ft_strdup("-2147483648");
		if (!str_nbr)
			return (NULL);
        return (str_nbr);
    }
	if (nbr == 0)
	{
		str_nbr[0] = '0';
		str_nbr[1] = '\0';
		return (str_nbr);
	}
	if (nbr < 0)
	{
		len++;
		str_nbr[0] = '-';
		nbr *= -1;
	}
	str_nbr[len] = '\0';
	while (nbr > 0)
	{
		str_nbr[len - 1] = (nbr % 10) + '0';
		nbr = nbr / 10;
		len--; 
	}
	return (str_nbr);
}

#include <stdio.h>

int main(int ac, char **av)
{
	(void)ac;
	char *result;

	result = ft_itoa(atoi(av[1]));

	printf("result = %s\n", result);
}
