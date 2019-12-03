/*
** EPITECH PROJECT, 2017
** navy
** File description:
** navy.c
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>

#define CASE map[1 + pos[1] - '0'][(pos[0] - '@') * 2]

void handler(int, siginfo_t *, void *);

int check_boat_dir(char *, char **);
int check_pos_in_tab(char *, int);
int filling_map(char **, char *);
int horizontal(char *, char **);
int check_boat_numbers(char **);
int check_hit(char **, char *);
int vertical(char *, char **);
int check_pos_writing(char *);
int check_pos(char *, int);
void ok(char **);
void create_pos(char **);
int my_putstr(char *);
int my_getnbr(char *);
void my_putchar(char);
char **create_map();
void my_putnbr(int);
void help();
void init_player();
int check_players();
void show_maps(char **, char **);
void phase1(int sig);
void phase2();
void phase3(int sig);

typedef struct player_s {
	pid_t pid_ennemy;
	char **map_one;
	char **map_two;
	int prec_sig;
	int phase;
	char *pos;
} player_t;

player_t players;
