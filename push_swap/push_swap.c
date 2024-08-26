/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:48:54 by junseyun          #+#    #+#             */
/*   Updated: 2024/08/16 14:52:31 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	setup_vals(t_vals *vals)
{
	vals->stack_a = (t_stack *)malloc(sizeof(t_stack));
	vals->stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!(vals->stack_a) || !(vals->stack_b))
		exception_msg();
	vals->size = 0;
	vals->stack_a->size = 0;
	vals->stack_b->size = 0;
	vals->stack_a->top = NULL;
	vals->stack_a->bottom = NULL;
	vals->stack_b->top = NULL;
	vals->stack_b->bottom = NULL;
}

static int	check_arr_size(int argc, char *argv[], t_vals *vals)
{
	int		i;
	int		size;
	int		total_size;
	char	**res;

	i = 0;
	total_size = 0;
	while (i < argc - 1)
	{
		size = 0;
		res = ft_split_arr(argv[i + 1], &size);
		if (!(res[0]))
		{
			free_str(res);
			free_stack_all(vals, 0);
			exception_msg();
		}
		free_str(res);
		total_size += size;
		i++;
	}
	return (total_size);
}

static void	create_arr(char *argv[], int *arr, int total_size, t_vals *vals)
{
	int		i;
	int		j;
	int		size;
	int		num;
	char	**res;

	i = 0;
	num = 0;
	while (num < total_size)
	{
		j = 0;
		size = 0;
		res = ft_split_arr(argv[i + 1], &size);
		if (!(res[0]))
		{
			free_str(res);
			exception_msg();
		}
		while (j < size)
			arr[num++] = ft_atoi(res[j++], res, arr, vals);
		i++;
		free_str(res);
	}
}

static int	*create_stack(int argc, char *argv[], t_vals *vals, int n)
{
	int		total_size;
	int		*stack_arr;
	t_node	*new_node;

	n = 0;
	total_size = check_arr_size(argc, argv, vals);
	stack_arr = (int *)malloc(sizeof(int) * total_size);
	if (!(stack_arr))
	{
		free_stack_all(vals, 0);
		exception_msg();
	}
	create_arr(argv, stack_arr, total_size, vals);
	while (n < total_size)
	{
		new_node = create_node(stack_arr[n++]);
		stack_push_bottom(vals->stack_a, new_node);
	}
	return (stack_arr);
}

int	main(int argc, char *argv[])
{
	int		flag;
	int		*arr;
	char	**res;
	t_vals	vals;

	if (argc < 2)
		return (0);
	res = 0;
	check_arr(argv, 0, res);
	setup_vals(&vals);
	arr = create_stack(argc, argv, &vals, 0);
	flag = check_stack_arr(&vals, arr, 0, 0);
	if (flag == 0)
	{
		free_stack_all(&vals, 0);
		free(arr);
		return (0);
	}
	free(arr);
	arr = NULL;
	indexing_val(&vals, 0, 0, 0);
	sort(&vals);
	free_stack_all(&vals, 0);
	return (0);
}
