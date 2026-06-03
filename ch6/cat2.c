/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inho <inho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 20:53:20 by inho              #+#    #+#             */
/*   Updated: 2026/06/03 21:17:19 by inho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int i;

	i = 1;
	while (i < argc)
	{
		FILE *f;
		int c;

		f = fopen(argv[i], "r");
		if (!f)
		{
			perror(argv[i]);
			exit(1);
		}
		while ((c = fgetc(f)) != EOF)
		{
			if (putchar(c) < 0)
				exit(1);
		}
		fclose(f);
		i++;
	}
}