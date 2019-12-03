/*
** EPITECH PROJECT, 2017
** navy
** File description:
** printing_map.c
*/

#include "include/my.h"
#include "include/get_next_line.h"

void show_maps(char **map1, char **map2)
{
	int i = -1;

	my_putstr("\nmy positions :\n");
	while (map1[++i] != NULL)
		my_putstr(map1[i]);
	i = -1;
	my_putstr("\nennemy's positions :\n");
	while (map2[++i] != NULL)
		my_putstr(map2[i]);
	my_putstr("\n");
}

void create_pos(char **map)
{
	int i = -1;
	int j = 1;
	int let = 65;

	while (map[++i] != NULL) {
		if (i > 1)
			map[i][0] = i + '0' - 1;
		if (i == 0)
			while (++j < 17) {
				map[i][j++] = let++;
				map[i][j] = ' ';
			}
		if (i == 1)
			while (j > 1)
				map[i][--j - 1] = '-';
			map[i][1] = '|';
	}
	map[1][1] = '+';
	map[0][0] = ' ';
}

char **create_map()
{
	char **map = malloc(sizeof(char *) * 11);
	int i = -1;
	int j = -1;

	while (++i < 10) {
		map[i] = malloc(sizeof(char) * 20);
		while (++j < 17) {
			map[i][j++] = '.';
			map[i][j] = ' ';
		}
		map[i][j++] = '\n';
		map[i][j] = '\0';
		j = -1;
	}
	map[i] = NULL;
	create_pos(map);
	return (map);
}
