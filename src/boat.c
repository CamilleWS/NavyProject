/*
** EPITECH PROJECT, 2017
** navy
** File description:
** boat.c
*/

#include "include/my.h"
#include "include/get_next_line.h"

int vertical(char *str, char **map)
{
	int i = -1;

	while ((str[3] + i) != str[6])
		map[1 + (str[3] - '/') + i++][(str[2] - '@') * 2]  = str[0];
	return (0);
}

int horizontal(char *str, char **map)
{
	int i = -1;

	while ((str[2] + i) != str[5])
		map[str[3] - '/'][2 + 2 * ((str[2] - '@') + i++)] = str[0];
	return (0);
}

int check_boat_numbers(char **map)
{
	int i = 1;
	int j = 1;
	int numbers = 0;

	while (++i < 10) {
		while (++j < 17)
			if (map[i][j] != ' ' && map[i][j++] != '.')
				numbers++;
		j = 1;
	}
	if (numbers != 14)
		return (-1);
	return (0);
}

int check_boat_dir(char *str, char **map)
{
	int ret;

	if (((str[2] - str[5]) == str[0] - '1') || \
	((str[5] - str[2]) == str[0] - '1'))
		if (str[3] == str[6])
			ret = horizontal(str, map);
		else
			ret = -1;
	else if (((str[3] - str[6]) == str[0] - '1') || \
	((str[6] - str[3]) == str[0] - '1'))
		if (str[2] == str[5])
			ret = vertical(str, map);
		else
			ret = -1;
	else
		ret = -1;
	ret = check_boat_numbers(map);
	return (ret);
}

int filling_map(char **map, char *path)
{
	int fd = open(path, O_RDONLY);
	char str[9];
	int ret = 1;

	if (fd < 0)
		return (-1);
	read(fd, str, 8);
	while (str != NULL && ret > 0) {
		ret = check_pos_writing(str);
		if (ret == 0) {
			check_boat_dir(str, map);
		}
		ret = read(fd, str, 8);
	}
	return (ret);
}
