/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:46:14 by apaghera          #+#    #+#             */
/*   Updated: 2023/01/23 14:51:02 by apaghera         ###   ########.fr       */
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