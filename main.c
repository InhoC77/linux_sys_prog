/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inho <inho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 22:55:27 by inho              #+#    #+#             */
/*   Updated: 2026/06/03 23:03:20 by inho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	int			n;
	int			i;
	static char	*buf;
	char		*result;
	char		*tmp;

	if (fd < 0)
		return (NULL);
	result = str;
	i = 0;
	while (1)
	{
		if (buf)
		{
			while (i < strlen(buf))
			{
				if (buf[i] == '\n')
				{
					i++;
                    // result에 \n까지 buf 추가
                    // 남은 buf 수정하고 free처리
                    return result;
				}
                // result에 buf 추가
                // free(buf);
			}
		}
		n = read(fd, buf, buffer_size);
	}
}

