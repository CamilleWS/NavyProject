/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/
#include "include/my.h"
#include "include/get_next_line.h"

void init_player()
{
	players.map_one = create_map();
	players.map_two = create_map();
	players.phase = 0;
	players.pid_ennemy = 0;
	players.prec_sig = 8;
	players.pos = malloc(sizeof(char) * 3);
}

int check_players(int ac, char **av)
{
	if (ac == 2) {
		filling_map(players.map_one, av[1]);
		ok(av);
	} else if (ac == 3) {
		filling_map(players.map_one, av[2]);
		players.pid_ennemy = my_getnbr(av[1]);
		kill(players.pid_ennemy, 12);
		my_putstr("waiting for ennemy's attack. . .\n");
		players.phase = 1;
	} else {
		help();
		return (84);
	}
	return (0);
}
