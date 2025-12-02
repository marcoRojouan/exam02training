/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:15:55 by mrojouan          #+#    #+#             */
/*   Updated: 2025/11/10 16:28:16 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

void	bah_faut_une_autre_fonction(char **tab, t_point size, char zero_or_not, int row, int col)
{
	if (row < 0 || col < 0 || row >= size.y || col >= size.x)
		return ;
	if (tab[row][col] == 'F' || tab[row][col] != zero_or_not)
		return ;

	tab[row][col] = 'F';

	bah_faut_une_autre_fonction(tab, size, zero_or_not, row - 1, col);
	bah_faut_une_autre_fonction(tab, size, zero_or_not, row + 1, col);
	bah_faut_une_autre_fonction(tab, size, zero_or_not, row, col - 1);
	bah_faut_une_autre_fonction(tab, size, zero_or_not, row, col + 1);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char zero_or_not = tab[begin.y][begin.x];
	
	bah_faut_une_autre_fonction(tab, size, zero_or_not, begin.y, begin.x);
}