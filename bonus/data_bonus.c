/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:29:04 by apaghera          #+#    #+#             */
/*   Updated: 2023/02/18 15:05:45 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_data	init_data(int argc, char **argv, char **envp)
{
	t_data	data;

	data.argc = argc;
	data.argv = argv;
	data.envp = envp;
	return (data);
}

t_parse	init_parsing_values(void)
{
	t_parse	parse;

	parse.path = NULL;
	parse.dir = NULL;
	return (parse);
}

void	init_pipes(t_data *data)
{
	int	i;

	i = -1;
	data->pipes = (t_pipe *)malloc(sizeof(t_pipe) * data->argc - 3);
	if (!data->pipes)
		return ;
	while (++i < data->argc - 3)
	{
		pipe(data->pipes[i].pipe);
	}
}

void	get_data_files(t_data *data)
{
	data->input.file = ft_strdup(data->argv[1]);
	data->output.file = ft_strdup(data->argv[data->argc - 1]);
}
