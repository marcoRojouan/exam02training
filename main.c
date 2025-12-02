/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:29:06 by mrojouan          #+#    #+#             */
/*   Updated: 2025/11/11 10:04:52 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
// #include "flood_fill.h"

// // Fonction utilitaire pour dupliquer un tableau de chaînes
// char **make_area(char **zone, t_point size)
// {
// 	char **area = malloc(sizeof(char *) * (size.y + 1));
// 	for (int y = 0; y < size.y; y++)
// 	{
// 		area[y] = malloc(sizeof(char) * (size.x + 1));
// 		for (int x = 0; x < size.x; x++)
// 			area[y][x] = zone[y][x];
// 		area[y][size.x] = '\0';
// 	}
// 	area[size.y] = NULL;
// 	return (area);
// }

// // Affiche le tableau sous forme de grille
// void print_tab(char **tab, t_point size)
// {
// 	for (int y = 0; y < size.y; y++)
// 	{
// 		for (int x = 0; x < size.x; x++)
// 			printf("%c", tab[y][x]);
// 		printf("\n");
// 	}
// }

// int main(void)
// {
// 	t_point size = {8, 5};
// 	t_point begin = {4, 2};
// 	char *zone[] = {
// 		"11111111",
// 		"10001001",
// 		"10010001",
// 		"10110001",
// 		"11100001"
// 	};

// 	char **area = make_area(zone, size);

// 	printf("Avant flood_fill :\n");
// 	print_tab(area, size);
// 	flood_fill(area, size, begin);
// 	printf("\nAprès flood_fill :\n");
// 	print_tab(area, size);

// 	// Libération mémoire
// 	for (int y = 0; y < size.y; y++)
// 		free(area[y]);
// 	free(area);

// 	return (0);
// }
