/*
** EPITECH PROJECT, 2017
** navy
** File description:
** boat.c
*/

#include "include/my.h"
#include "include/get_next_line.h"

//#define CASE map[1 + pos[1] - '0'][(pos[0] - '@') * 2]

int check_hit(char **map, char *pos)
{
	if (CASE > '1' && CASE < '6') {
		CASE = 'x';
        	return (2);
	}
	CASE = 'o';
	return (1);
}
