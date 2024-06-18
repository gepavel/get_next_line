/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepavel <gepavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:10:14 by gepavel           #+#    #+#             */
/*   Updated: 2024/06/18 15:25:05 by gepavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*str1;
	char	*str2;
	char	*str3;
	int		clean = 0;

	fd1 = open("text1.txt", O_RDONLY);
	fd2 = open("text2.txt", O_RDONLY);
	fd3 = open("text3.txt", O_RDONLY);
	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
		return (str1 = NULL, printf("wrong fd"), 0);
	while (clean == 0)
	{
		str1 = get_next_line(fd1);
		str2 = get_next_line(fd2);
		str3 = get_next_line(fd3);
		if (str1 != NULL && str2 != NULL && str3 != NULL)
		{
			printf("[%s]\n", str1);
			printf("[%s]\n", str2);
			printf("[%s]\n", str3);
			free(str1);
			free(str2);
			free(str3);
		}
		else
			clean = 1;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
