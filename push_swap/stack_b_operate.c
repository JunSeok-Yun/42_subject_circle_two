/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_operate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:00:13 by junseyun          #+#    #+#             */
/*   Updated: 2024/08/16 15:01:08 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	sb(t_vals *vals, int num)
{
	int	temp;

	if (vals->stack_b->size < 2)
		return ;
	temp = vals->stack_b->top->data;
	vals->stack_b->top->data = vals->stack_b->top->next->data;
	vals->stack_b->top->next->data = temp;
	if (num == 1)
		ft_printf("sb\n");
}

void	pb(t_vals *vals)
{
	t_node	*temp;

	if (vals->stack_a->size < 1)
		return ;
	temp = stack_pop_top(vals->stack_a);
	stack_push_top(vals->stack_b, temp);
	ft_printf("pb\n");
}

void	rb(t_vals *vals, int num)
{
	t_node	*temp;

	if (vals->stack_b->size < 2)
		return ;
	temp = stack_pop_top(vals->stack_b);
	stack_push_bottom(vals->stack_b, temp);
	if (num == 1)
		ft_printf("rb\n");
}

void	rrb(t_vals *vals, int num)
{
	t_node	*temp;

	if (vals->stack_b->size < 2)
		return ;
	temp = stack_pop_bottom(vals->stack_b);
	stack_push_top(vals->stack_b, temp);
	if (num == 1)
		ft_printf("rrb\n");
}
