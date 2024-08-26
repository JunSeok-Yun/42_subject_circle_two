/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:36:37 by junseyun          #+#    #+#             */
/*   Updated: 2024/07/24 17:40:35 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_header.h"

int	exception_msg(char *str)
{
	write(2, str, ft_strlen(str));
	return (1);
}

void	exception_err_msg(char *str)
{
	perror(str);
	exit (1);
}
