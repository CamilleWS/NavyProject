/*
** EPITECH PROJECT, 2017
** navy
** File description:
** map.c
*/

#include "include/my.h"
#include "include/get_next_line.h"

int check_pos_in_tab(char *str, int i)
{
	if (str[i] > '@' && str[i] < 'I')
		if (str[i + 1] > '0' && str[i + 1] < '9')
			return (0);
	return (-1);
}

int check_pos_writing(char *str)
{
	int ret;

	if (str[0] > '1' && str[0] < '6' && str[1] == ':' && str[4] == ':')
		ret = check_pos_in_tab(str, 2);
		if (ret == 0)
			ret = check_pos_in_tab(str, 5);
	return (ret);
}
