/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inho <inho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:09:58 by inho              #+#    #+#             */
/*   Updated: 2026/06/01 22:15:17 by inho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 42

static void	do_cat(const char *path);
static void	die(const char *s);

int	main(int argc, char *argv[])
{
	int	i;

	if (argc < 2)
	{
		fprintf(stderr, "%s: file name not given\n", argv[0]);
		exit(1);
	}
	i = 1;
	while (i < argc)
		do_cat(argv[i++]);
	exit(0);
}

static void	do_cat(const char *path)
{
	int				fd;
	unsigned char	buf[BUFFER_SIZE];
	int				n;
	int				i;

	i = 1;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		die(path);
	while (1)
	{
		n = read(fd, buf, sizeof(buf));
		if (n < 0)
			die(path);
		if (n == 0)
			break ;
		if (write(STDOUT_FILENO, buf, n) < 0)
			die(path);
	}
	if (close(fd) < 0)
		die(path);
}

static void	die(const char *s)
{
	perror(s);
	exit(1);
}
