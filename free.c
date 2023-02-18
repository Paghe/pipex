/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:42:29 by apaghera          #+#    #+#             */
/*   Updated: 2023/02/15 15:45:22 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_pointers(t_parse parse)
{
	int	i;

	i = 0;
	while (parse.dir[i])
	{
		free(parse.dir[i]);
		i++;
	}
	free(parse.dir);
}
