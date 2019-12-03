/*
** EPITECH PROJECT, 2017
** get_next_line
** File description:
** get_next_line.c
*/

#include "include/my.h"
#include "include/get_next_line.h"

int my_strlen(char *str)
{
	int i = -1;

	while (str[++i] != '\0');
	return (i);
}

char *my_strcat(char *str1, char c)
{
	char *str = malloc(sizeof(char) * (my_strlen(str1) + 2));
	int i = -1;

	while (str1[++i] != '\0')
		str[i] = str1[i];
	str[i++] = c;
	str[i] = '\0';
	return (str);
}

test_t *boucle(char *buffer, char *buf, int fd)
{
	test_t *info = malloc(sizeof(*info));
	int i = -1;

	while (1) {
		while (buffer[++i] != '\n' && buffer[i] != '\0')
			buf = my_strcat(buf, buffer[i]);
		if (buffer[i] == '\n' || (buffer[i] == '\0' && i != READ_SIZE)) {
			info->i = i;
			info->str = malloc(my_strlen(buf) + 1);
			info->str = buf;
			info->fd = fd;
			read(fd, buffer, READ_SIZE);
			return (info);
		}
		read(fd, buffer, READ_SIZE);
		i = -1;
	}
}

int init(char *buffer, int fd)
{
	static int j = 0;

	if (j == 0) {
		j++;
		buffer[0] = '0';
	} else
		buffer[READ_SIZE] = '\0';
	return (read(fd, buffer, READ_SIZE));
}

char *get_next_line(int fd)
{
	test_t *info = malloc(sizeof(*info));
	static char buffer[READ_SIZE + 1];
	char *buf = malloc(READ_SIZE + 1);
	static int i = 0;
	int ret;

	ret = init(buffer, fd);
	if (ret < 0)
		return NULL;
	if (buffer[i] == '\n')
		while (buffer[++i] != '\0' && buffer[i] != '\n') {
			buf = my_strcat(buf, buffer[i]);
		}
	if (buffer[i] == '\n' || (buffer[i] == '\0' && i != READ_SIZE))
		return (buf);
	i = 0;
	if (read(fd, buffer, READ_SIZE) <= 0) {
		return (NULL);
	}
	info = boucle(buffer, buf, fd);
	i = info->i;
	fd = info->fd;
	return(info->str);
}
