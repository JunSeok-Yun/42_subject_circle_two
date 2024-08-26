/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:55:45 by junseyun          #+#    #+#             */
/*   Updated: 2024/08/16 14:57:28 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing_val(t_vals *vals, int num, int next_num, int idx)
{
	t_node	*temp;
	t_node	*next_temp;

	temp = vals->stack_a->top;
	while (temp != vals->stack_a->bottom)
	{
		num = temp->data;
		next_temp = temp->next;
		while (next_temp != vals->stack_a->top)
		{
			next_num = next_temp->data;
			if (num > next_num)
			{
				idx = temp->idx;
				temp->idx = idx + 1;
			}
			else if (num < next_num)
			{
				idx = next_temp->idx;
				next_temp->idx = idx + 1;
			}
			next_temp = next_temp->next;
		}
		temp = temp->next;
	}
}

int	solve_max_bit(t_vals *vals, int temp_idx)
{
	int		i;
	int		max_idx;
	int		max_bit;
	t_node	*temp;

	max_idx = 0;
	max_bit = 0;
	i = 0;
	temp = vals->stack_a->top;
	while (i < vals->stack_a->size)
	{
		temp_idx = temp->idx;
		if (temp_idx > max_idx)
			max_idx = temp_idx;
		temp = temp->next;
		i++;
	}
	while ((max_idx >> max_bit) != 0)
		max_bit++;
	return (max_bit);
}

void	radix_sort_a(t_vals *vals, int i, int temp_idx)
{
	if (((temp_idx >> i) & 1) == 1)
		ra(vals, 1);
	else
		pb(vals);
}

void	radix_sort(t_vals *vals, int i, int j)
{
	int		max_bit;
	int		stack_size;
	int		temp_idx;
	t_node	*temp;

	max_bit = solve_max_bit(vals, 0);
	while (i < max_bit)
	{
		j = 0;
		temp = vals->stack_a->top;
		stack_size = vals->stack_a->size;
		while (j < stack_size)
		{
			temp_idx = temp->idx;
			temp = temp->next;
			radix_sort_a(vals, i, temp_idx);
			j++;
		}
		j = vals->stack_b->size;
		while (j-- > 0)
			pa(vals);
		i++;
	}
}

void	sort(t_vals *vals)
{
	if (vals->stack_a->size == 2)
	{
		if (vals->stack_a->top->data > vals->stack_a->bottom->data)
			sa(vals, 1);
	}
	else if (vals->stack_a->size == 3)
		simple_sort_3(vals, 0, 0, 0);
	else if (vals->stack_a->size == 4)
		simple_sort_4(vals, 0, 0);
	else if (vals->stack_a->size == 5)
		simple_sort_5(vals, 0, 0);
	else
		radix_sort(vals, 0, 0);
}
