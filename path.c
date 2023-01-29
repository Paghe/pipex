/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:14:10 by apaghera          #+#    #+#             */
/*   Updated: 2023/01/29 15:19:25 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	get_path(char *path, char split)
{
	int		i;
	char	*cmd;

	while (path[i])
	{
		cmd[i] = ft_split(path[i], split);
		i++;
	}
	return (cmd);
}
