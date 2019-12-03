/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/
#include "include/my.h"
#include "include/get_next_line.h"

void	help()
{
	my_putstr("USAGE\n ./navy [first_player_pid] navy_positions\n");
	my_putstr("DESCRIPTION\n first_player_pid: only for th 2nd player. ");
	my_putstr("pid of the first player.\n navy_positions: ");
	my_putstr("file representing the positions of the ships.\n");
}
