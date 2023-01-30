/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 20:04:18 by apaghera          #+#    #+#             */
/*   Updated: 2023/01/30 21:03:27 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_args(char *argv)
{
	char	*s;

	printf("%s\n", "HELLO");
	s = ft_strrchr(argv, ' ') + 1;
	printf("%s\n", s);
	return (s);
}
