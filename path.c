/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:14:10 by apaghera          #+#    #+#             */
/*   Updated: 2023/01/30 21:15:22 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	while (envp[i])
	{
		if (envp[i] == ft_strnstr(envp[i], "PATH", 4))
			path = envp[i];
		i++;
	}	
	return (path);
}

char	**get_commands(char *path, char split)
{
	char	**cmd;
	int		i;

	cmd = ft_split(path + 5, split);
	i = 0;
	return (cmd);
}

char	*exec_cmd(char **path, char *argv)
{
	char	*tmp;
	int		i;
	char	*cmd;
	int		j;

	i = 0;
	j = 0;
	while (path[i])
	{
		j = 0;
		tmp = ft_strjoin(path[i], "/");
		cmd = ft_strjoin(tmp, argv);
		while (cmd[j] != ' ')
			j++;
		cmd[j] = '\0';
		free(tmp);
		printf("%s\n", "cmd");
		if (access(cmd, 0) == 0)
		{
			printf("%s\n", cmd);
			return (cmd);
		}	
		i++;
	}
	return (NULL);
}
