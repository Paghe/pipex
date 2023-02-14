/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:46:14 by apaghera          #+#    #+#             */
/*   Updated: 2023/02/07 14:59:18 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_input_data	init_input(int argc, char **argv, char **envp)
{
	t_input_data	data;

	data.argc = argc;
	if (data.argc != 5)
		exit(EXIT_FAILURE);
	data.argv = argv;
	if (!data.argv)
		exit(EXIT_FAILURE);
	argv_error(data.argv);
	data.envp = envp;
	if (!data.envp)
		exit(EXIT_FAILURE);
	return (data);
}

t_data_object	init_object(void)
{
	t_data_object	object;

	object.i = 0;
	object.o = 0;
	return (object);
}
