/*
** EPITECH PROJECT, 2017
** navy
** File description:
** navy.c
*/

#include "include/my.h"
#include "include/get_next_line.h"

player_t players;

void	*my_memset(void *connection, int zero, size_t size_connection)
{
	size_t i;

	for (i = 0; i < size_connection; i++)
		((unsigned char *)connection)[i] = zero;
	return (connection);
}

void ok(char **av)
{
	if (av[1][0] == '-' && av[1][1] == 'h') {
		help();
	}
	else {
		my_putstr("my_pid: ");
		my_putnbr(getpid());
		my_putstr("\nwaiting for enemy connection...\n");
	}
}

void handler(int sig, siginfo_t *info, void *context)
{
	(void)context;

	if (sig == 12 && players.phase == 0) {
		players.pid_ennemy = info->si_pid;
		my_putstr("enemy connected\n");
		show_maps(players.map_one, players.map_two);
		players.phase = 2;
		phase2();
	}
	if (players.phase == 1 && (sig == 12 || sig == 10))
		phase1(sig);
	else if (players.phase == 3 && (sig == 12 || sig == 10))
		phase3(sig);
	usleep(10);
}

int	main(int ac, char **av)
{
	struct sigaction connection;

	init_player();
	my_memset(&connection, 0, sizeof(connection));
	connection.sa_sigaction = &handler;
	connection.sa_flags = SA_SIGINFO;
	if (check_players(ac, av) == 84)
		return (0);
	if (players.pid_ennemy != 0) {
		my_putstr("successfully connected\n");
		show_maps(players.map_one, players.map_two);
		my_putstr("waiting for ennemy's attack. . .\n");
		players.phase = 1;
	}
	sigaction(10, &connection, NULL);
	sigaction(12, &connection, NULL);
	while (1) {
		usleep(4000000000);
	}
}
