/*
** EPITECH PROJECT, 2017
** navy
** File description:
** navy.c
*/

#include "include/my.h"
#include "include/get_next_line.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}

int my_putstr(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		my_putchar(str[i]);
		i += 1;
	}
	return (0);
}

void my_putnbr(int nb)
{
	int i;

	if (nb < 0) {
		my_putchar(nb + '0');
		nb = nb * (-1);
	}
	if (nb < 10)
	my_putchar(nb + '0');
	else if (nb > 9) {
		my_putnbr(nb / 10);
		i = nb % 10;
		my_putchar(i + '0');
	}
}

int     my_getnbr(char *str)
{
	long nb = 0;
	int i = -1;
	int neg = 1;

	while (str[++i] == '-' || str[i] == '+')
		neg *= -1;
	while (str[i] != '\0') {
		if (str[i] >= '0' && str[i] <= '9')
			nb = nb * 10 + str[i++] - '0';
	}
	return (neg * nb);
}
