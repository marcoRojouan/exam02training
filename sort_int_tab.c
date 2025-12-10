/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:17:56 by mrojouan          #+#    #+#             */
/*   Updated: 2025/12/10 12:16:35 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int sort_int_tab(int *tab, unsigned int size)
{
	int tmp;
	unsigned int i = 0;
	unsigned int j;

	while (i < (size - 1))
	{
		j = i;
		while (j < size)
		{
			if (tab[j] < tab[i])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
