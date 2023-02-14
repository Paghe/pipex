/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:37:36 by apaghera          #+#    #+#             */
/*   Updated: 2023/02/09 21:55:00 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	err_handle(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

int	err_fork(void)
{
	perror("Fork: ");
	exit(-1);
}

int	error_msg(char *msg)
{
	write(2, msg, ft_strlen(msg));
	return (1);
}

int	argv_error(char **argv)
{
	int	j;

	j = 0;
	while (argv[j])
	{
		if (argv[j][0] == '\0')
		{
			ft_putstr_fd("Empty Arguments", 2);
			return (EXIT_FAILURE);
		}
		j++;
	}
	return (0);
}

int	err_pipe(int *pipe0)
{
	err_handle("pipe error");
	close(pipe0[0]);
	close(pipe0[1]);
	exit(1);
}
