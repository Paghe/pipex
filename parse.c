/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:54:08 by apaghera          #+#    #+#             */
/*   Updated: 2023/02/17 17:32:07 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **envp)
{
	char	*path;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (envp[i] == ft_strnstr(envp[i], "PATH", 4))
			path = ft_strdup(envp[i]);
		i++;
	}
	return (path);
}

char	**get_dir(char *path)
{
	char	**dir;

	dir = ft_split(path + 5, ':');
	free(path);
	return (dir);
}

char	*get_file(t_parse parse, t_data data, int size)
{
	char	*tmp;
	int		j;
	int		i;
	t_file	file;

	i = 0;
	while (parse.dir[i])
	{
		j = 0;
		tmp = ft_strjoin(parse.dir[i], "/");
		if (ft_strrchr(data.argv[size], '/') && \
				(*(ft_strrchr(data.argv[size], '/') + 1)) != '\0')
			file.file = different_format(file, tmp, data.argv[size]);
		else
			file.file = ft_strjoin(tmp, data.argv[size]);
		free(tmp);
		skip_space(file, j);
		if (access(file.file, X_OK) == 0)
			return (file.file);
		free(file.file);
		i++;
	}
	return (NULL);
}

char	*get_exec_file(t_parse parse, t_cmd *cmd, t_data data)
{
	t_file	file;
	int		size;
	int		i;

	i = 0;
	size = 2;
	parse.path = get_path(data.envp);
	parse.dir = get_dir(parse.path);
	file.file = NULL;
	while (i < data.argc - 3)
	{
		cmd[i].file.file = get_file(parse, data, size);
		size++;
		i++;
	}
	free_pointers(parse);
	return (file.file);
}
