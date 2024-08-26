/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:57:42 by junseyun          #+#    #+#             */
/*   Updated: 2024/08/16 14:58:52 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_depth(t_vals *vals, int min_idx)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = vals->stack_a->top;
	while (i < vals->stack_a->size)
	{
		if (min_idx == temp->idx)
			return (i);
		temp = temp->next;
		i++;
	}
	return (0);
}

static int	find_min(t_vals *vals)
{
	int		min_idx;
	int		i;
	t_node	*temp;

	i = 0;
	min_idx = vals->stack_a->size + 1;
	temp = vals->stack_a->top;
	while (i < vals->stack_a->size)
	{
		if (min_idx > temp->idx)
			min_idx = temp->idx;
		temp = temp->next;
		i++;
	}
	return (min_idx);
}

void	simple_sort_3(t_vals *vals, int top, int mid, int bottom)
{
	top = vals->stack_a->top->data;
	mid = vals->stack_a->top->next->data;
	bottom = vals->stack_a->bottom->data;
	if (top < mid && top < bottom && mid > bottom)
	{
		sa(vals, 1);
		ra(vals, 1);
	}
	else if (top > mid && mid < bottom && bottom > top)
		sa(vals, 1);
	else if (top < mid && mid > bottom && top > bottom)
		rra(vals, 1);
	else if (top > mid && mid < bottom && top > bottom)
		ra(vals, 1);
	else if (top > mid && top > bottom && mid > bottom)
	{
		sa(vals, 1);
		rra(vals, 1);
	}
}

void	simple_sort_4(t_vals *vals, int min_idx, int depth)
{
	min_idx = find_min(vals);
	depth = get_depth(vals, min_idx);
	if (depth == 1)
		sa(vals, 1);
	else if (depth == 2)
	{
		ra(vals, 1);
		ra(vals, 1);
	}
	else if (depth == 3)
		rra(vals, 1);
	pb(vals);
	simple_sort_3(vals, 0, 0, 0);
	pa(vals);
}

void	simple_sort_5(t_vals *vals, int min_idx, int depth)
{
	min_idx = find_min(vals);
	depth = get_depth(vals, min_idx);
	if (depth == 1)
		sa(vals, 1);
	else if (depth == 2)
	{
		ra(vals, 1);
		ra(vals, 1);
	}
	else if (depth == 3)
	{
		rra(vals, 1);
		rra(vals, 1);
	}
	else if (depth == 4)
		rra(vals, 1);
	pb(vals);
	indexing_val(vals, 0, 0, 0);
	simple_sort_4(vals, 0, 0);
	pa(vals);
}
