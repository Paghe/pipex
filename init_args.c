/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 20:04:18 by apaghera          #+#    #+#             */
/*   Updated: 2023/02/05 19:22:02 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd	*init_args(t_cmd *cmd, t_input_data data)
{
	int				i;
	int				j;

	j = 0;
	i = 1;
	cmd = (t_cmd *)malloc(sizeof(t_cmd) * data.argc - 3);
	if (!cmd)
		exit(EXIT_FAILURE);
	while (++i < data.argc)
		cmd[j++].cmd = ft_split(data.argv[i], ' ');
	return (cmd);
}
