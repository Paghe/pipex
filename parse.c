/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 20:04:18 by apaghera          #+#    #+#             */
/*   Updated: 2023/01/31 15:15:53 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd	*get_args(t_cmd *cmd, t_input_data data)
{
	int				i;
	int				j;

	j = 0;
	i = 1;
	cmd = (t_cmd *)malloc(sizeof(t_cmd) * data.argc - 3);
	while (++i < data.argc)
		cmd[j++].cmd = ft_split(data.argv[i], ' ');
/* 	printf("%s\n", cmd[0].cmd[0]);
	printf("%s\n", cmd[0].cmd[1]);
	printf("%s\n", cmd[1].cmd[0]);
	printf("%s\n", cmd[1].cmd[1]); */
	return (cmd);
}
