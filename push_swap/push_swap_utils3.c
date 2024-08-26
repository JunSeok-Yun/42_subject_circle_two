/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:54:46 by junseyun          #+#    #+#             */
/*   Updated: 2024/08/17 16:37:01 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_dup_vals(t_vals *vals, int *arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < vals->stack_a->size - 1)
	{
		j = i + 1;
		while (j < vals->stack_a->size)
		{
			if (arr[i] == arr[j])
			{
				free_stack_all(vals, 0);
				free(arr);
				exception_msg();
			}
			j++;
		}
		i++;
	}
}

int	check_stack_arr(t_vals *vals, int *arr, int i, int flag)
{
	int	j;
	int	temp;

	while (i < vals->stack_a->size - 1)
	{
		j = i + 1;
		while (j < vals->stack_a->size)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				flag++;
			}
			j++;
		}
		i++;
	}
	check_dup_vals(vals, arr);
	return (flag);
}

void	check_arr(char *argv[], int flag, char **res)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		res = ft_split(argv[i]);
		if (!(res[0]))
		{
			free_str(res);
			exception_msg();
		}
		flag = check_res(res);
		if (flag == 1)
		{
			free_str(res);
			exception_msg();
		}
		free_str(res);
		i++;
	}
}

int	check_res(char **res)
{
	if (check_sign(res) == 1)
		return (1);
	if (check_digit(res) == 1)
		return (1);
	if (check_sign_loc(res) == 1)
		return (1);
	if (check_digit_range(res, 0, 0) == 1)
		return (1);
	return (0);
}
