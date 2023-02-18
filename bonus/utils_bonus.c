/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:55:07 by apaghera          #+#    #+#             */
/*   Updated: 2023/02/18 15:06:11 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	skip_space(t_file file, int j)
{
	while (file.file[j] && file.file[j] != ' ')
		j++;
	file.file[j] = '\0';
}

void	close_pipes(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->argc - 3)
	{
		close(data->pipes[i].pipe[0]);
		close(data->pipes[i].pipe[1]);
	}
}

void	redirect_pipes(t_data **data, int child_number)
{
	int	fd;

	if (child_number == 0)
	{
		fd = open((*data)->input.file, O_RDONLY);
		if (fd < 0)
			exit(1);
		redirect_io(fd, (*data)->pipes[child_number].pipe[WRITE_END]);
		close(fd);
	}
	if (child_number == (*data)->argc - 3 - 1)
	{
		fd = open((*data)->output.file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd < 0)
			exit(1);
		redirect_io((*data)->pipes[child_number - 1].pipe[READ_END], fd);
		close(fd);
	}
	else
	{
		redirect_io((*data)->pipes[child_number - 1].pipe[READ_END], \
					(*data)->pipes[child_number].pipe[WRITE_END]);
	}
}

char	*different_format(t_file file, char *tmp, char *argv)
{
	file.file = ft_strjoin(tmp, ft_strrchr(argv, '/'));
	return (file.file);
}
