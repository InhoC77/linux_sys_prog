/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inho <inho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:09:58 by inho              #+#    #+#             */
/*   Updated: 2026/06/02 04:09:26 by inho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 42

static void	do_wc_l(const char *path);
static void	die(const char *s);
static int	n_count(const unsigned char *buf, int size);

int	main(int argc, char *argv[])
{
	int		i;
	char	name[50];

	if (argc < 2)
	{
		fgets(name, sizeof(name), stdin);
		fputs(name, stdout);
	}
	i = 1;
	while (i < argc)
		do_wc_l(argv[i++]);
	exit(0);
}

static void	do_wc_l(const char *path)
{
	int				fd;
	unsigned char	buf[BUFFER_SIZE];
	int				n;
	int				count;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		die(path);
	count = 0;
	while (1)
	{
		n = read(fd, buf, sizeof(buf));
		count += n_count(buf, n);
		if (n < 0)
			die(path);
		if (n == 0)
			break ;
		// if (write(STDOUT_FILENO, buf, n) < 0)
		// 	die(path);
	}
	if (close(fd) < 0)
		die(path);
	printf("count: %d\n", count);
}

static void	die(const char *s)
{
	perror(s);
	exit(1);
}

static int	n_count(const unsigned char *buf, int size)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (i < size)
	{
		if (buf[i++] == '\n')
			count++;
	}
	return (count);
}