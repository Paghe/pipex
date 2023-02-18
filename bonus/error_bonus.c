/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:17:22 by apaghera          #+#    #+#             */
/*   Updated: 2023/02/18 15:05:51 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	err_handle(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

int	error_msg(char *msg)
{
	write(2, msg, ft_strlen(msg));
	return (1);
}
