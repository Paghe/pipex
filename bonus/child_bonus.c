/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:34:56 by apaghera          #+#    #+#             */
/*   Updated: 2023/02/18 15:05:41 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	execute_command(t_data *data, t_cmd *cmd, int child_number)
{
	data->pipes[child_number].pid = fork();
	if (data->pipes[child_number].pid < 0)
		err_handle("Fork: ");
	if (data->pipes[child_number].pid == 0)
	{
		redirect_pipes(&data, child_number);
		close_pipes(data);
		if (cmd[child_number].file.file == NULL)
		{
			err_handle(ERR_CMD);
			exit(127);
		}
		if (execve(cmd[child_number].file.file, \
					cmd[child_number].cmd, data->envp) == -1)
			err_handle("execve error: ");
	}
}

void	redirect_io(int input, int output)
{
	if (dup2(input, STDIN_FILENO) == -1)
		return ;
	if (dup2(output, STDOUT_FILENO) == -1)
		return ;
}
