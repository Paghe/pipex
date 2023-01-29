/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:46:14 by apaghera          #+#    #+#             */
/*   Updated: 2023/01/26 14:28:03 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_input_data	create_input(int argc, char **argv, char **envp)
{
	t_input_data	data;

	data.argc = argc;
	data.argv = argv;
	data.envp = envp;
	return (data);
}

t_data_object	create_object(void)
{
	t_data_object	object;
	int				input_file;
	int				output_file;

	input_file = 0;
	output_file = 0;
	object.input_file = input_file;
	object.output_file = output_file;
	return (object);
}
