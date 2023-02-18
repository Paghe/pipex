/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:44:07 by apaghera          #+#    #+#             */
/*   Updated: 2023/02/18 15:06:01 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	t_parse	parse;
	t_cmd	*cmd;
	int		child;

	if (argc < 5)
		return (1);
	if (!argv)
		return (1);
	child = -1;
	data = init_data(argc, argv, envp);
	parse = init_parsing_values();
	init_args(&cmd, data);
	init_pipes(&data);
	get_data_files(&data);
	get_exec_file(parse, cmd, data);
	while (++child < data.argc - 3)
		execute_command(&data, cmd, child);
	close_pipes(&data);
	waitpid(data.pipes->pid, &data.status, 0);
	system("leaks pipex");
	exit(WEXITSTATUS(data.status));
}
