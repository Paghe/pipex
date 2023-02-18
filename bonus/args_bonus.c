/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:39:38 by apaghera          #+#    #+#             */
/*   Updated: 2023/02/18 15:05:34 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	init_args(t_cmd **cmd, t_data data)
{
	int				i;
	int				j;

	j = 0;
	i = 1;
	*cmd = (t_cmd *)malloc(sizeof(t_cmd) * data.argc - 3);
	if (!*cmd)
		exit(EXIT_FAILURE);
	while (++i < data.argc)
	{
		(*cmd)[j].cmd = ft_split(data.argv[i], ' ');
		(*cmd)[j].file.file = NULL;
		j++;
	}
}
