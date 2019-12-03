/*
** EPITECH PROJECT, 2017
** get_next_line
** File description:
** get_next_line.h
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#ifndef READ_SIZE
	#define READ_SIZE (8)
#endif /* !READ_SIZE */

typedef struct test_s {
	int i;
	char *str;
	int fd;
} test_t;

test_t *boucle(char *, char *, int);
char *my_strcat(char *, char);
char *get_next_line(int);
int my_strlen(char *);
int init(char *, int);
