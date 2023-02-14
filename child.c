/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:54:54 by apaghera          #+#    #+#             */
/*   Updated: 2023/02/14 14:03:39 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(t_data_object *object, int **pipe0, \
					t_input_data *data, t_cmd *cmd)
{
	data->pid[0] = fork();
	if (data->pid[0] == -1)
		err_handle("Fork: ");
	if (data->pid[0] == 0)
		init_child1(object, pipe0, data, cmd);
}

void	child2(t_data_object *object, int **pipe0, \
					t_input_data *data, t_cmd *cmd)
{
	data->pid[1] = fork();
	if (data->pid[1] == -1)
		err_handle("Fork: ");
	if (data->pid[1] == 0)
		init_child2(object, pipe0, data, cmd);
}
