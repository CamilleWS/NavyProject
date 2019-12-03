/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include "include/my.h"

void phase1(int sig)
{
	static int i = -1;
	static int j = -1;
	char str[3] = "A1";

	if (sig == 12)
		++j;
	if (sig == 10 && players.prec_sig != 12)
		++i;
	else if (sig == 10 && players.prec_sig == 12) {
		str[0] += i;
		str[1] += j;
		str[2] = '\0';
		my_putstr(str);
		i = -1;
		j = -1;
		if (check_hit(players.map_one, str) == 1) {
			my_putstr(": missed\n");
			kill(players.pid_ennemy, 10);
		} else {
			my_putstr(": hit\n");
			kill(players.pid_ennemy, 12);
		}
		show_maps(players.map_one, players.map_two);
		phase2();
	}
	players.prec_sig = sig;
}

void phase2()
{
	int i = -1;
	int j = -1;
	int ret = -1;

	while (ret != 0) {
		my_putstr("attack: ");
		read(0, players.pos, 3);
		players.pos[2] = '\0';
		ret = check_pos_in_tab(players.pos, 0);
		if (ret != 0)
			my_putstr("wrong position\n");
	}
	my_putstr(players.pos);
	my_putstr(": ");
	while (++i + '@' != players.pos[0]) {
		kill(players.pid_ennemy, 10);
		usleep(10);
	}
	while (++j + '0' != players.pos[1]) {
		kill(players.pid_ennemy, 12);
		usleep(10);
	}
	kill(players.pid_ennemy, 10);
	players.phase = 3;
}

void phase3(int sig)
{
	usleep(10);
	if (sig == 10)
		my_putstr("missed\n\n");
	else if (sig == 12)
		my_putstr("hit\n\n");
	check_hit(players.map_two, players.pos);
	my_putstr("waiting for ennemy's attack. . .\n");
	players.prec_sig = 10;
	players.phase = 1;
}
