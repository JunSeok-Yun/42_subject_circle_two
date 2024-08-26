/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exception.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:03:25 by junseyun          #+#    #+#             */
/*   Updated: 2024/08/17 16:38:41 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sign(char **res)
{
	int	i;
	int	j;
	int	cnt;

	i = 0;
	while (res[i])
	{
		j = 0;
		cnt = 0;
		while (res[i][j])
		{
			if (res[i][j] == '+' || res[i][j] == '-')
				cnt++;
			if (cnt >= 2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_digit(char **res)
{
	int	i;
	int	j;

	i = 0;
	while (res[i])
	{
		j = 0;
		while (res[i][j])
		{
			if (res[i][j] == '+' || res[i][j] == '-')
			{
				if (res[i][j + 1] == 0)
					return (1);
				j++;
			}
			else if (!(res[i][j] >= '0' && res[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_sign_loc(char **res)
{
	int	i;
	int	j;

	i = 0;
	while (res[i])
	{
		j = 0;
		if (res[i][j] == '+' || res[i][j] == '-')
			j = 1;
		while (res[i][j])
		{
			if (res[i][j] == '-' || res[i][j] == '+')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_digit_range(char **res, int i, int len)
{
	int	flag;

	while (res[i])
	{
		len = 0;
		flag = 0;
		len = check_len(res, i, flag, len);
		if (len > 12)
			return (1);
		i++;
	}
	return (0);
}

int	check_len(char **res, int i, int flag, int len)
{
	int	j;

	j = 0;
	if (res[i][j] == '+' || res[i][j] == '-')
	{
		j = 1;
		len++;
	}
	while (res[i][j])
	{
		if (res[i][j] != '0')
			flag = 1;
		if (res[i][j] == '0' && flag == 0)
			j++;
		else
		{
			len++;
			j++;
		}
	}
	return (len);
}
