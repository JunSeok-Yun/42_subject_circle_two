/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:34:06 by junseyun          #+#    #+#             */
/*   Updated: 2024/08/16 14:43:35 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exception_free(char **arr, int *stack_arr, t_vals *vals)
{
	free_str(arr);
	free(stack_arr);
	free_stack_all(vals, 0);
	exception_msg();
}

int	ft_atoi(const char *str, char **arr, int *stack_arr, t_vals *vals)
{
	long long int	res;
	int				sign;

	sign = 1;
	res = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	if (*str != 0 || res > 2147483647 || res < -2147483648)
		exception_free(arr, stack_arr, vals);
	return ((int)(res * sign));
}
