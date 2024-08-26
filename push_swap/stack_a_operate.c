/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_operate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:59:16 by junseyun          #+#    #+#             */
/*   Updated: 2024/08/16 14:59:55 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	sa(t_vals *vals, int num)
{
	int	temp;

	if (vals->stack_a->size < 2)
		return ;
	temp = vals->stack_a->top->data;
	vals->stack_a->top->data = vals->stack_a->top->next->data;
	vals->stack_a->top->next->data = temp;
	if (num == 1)
		ft_printf("sa\n");
}

void	pa(t_vals *vals)
{
	t_node	*temp;

	if (vals->stack_b->size < 1)
		return ;
	temp = stack_pop_top(vals->stack_b);
	stack_push_top(vals->stack_a, temp);
	ft_printf("pa\n");
}

void	ra(t_vals *vals, int num)
{
	t_node	*temp;

	if (vals->stack_a->size < 2)
		return ;
	temp = stack_pop_top(vals->stack_a);
	stack_push_bottom(vals->stack_a, temp);
	if (num == 1)
		ft_printf("ra\n");
}

void	rra(t_vals *vals, int num)
{
	t_node	*temp;

	if (vals->stack_a->size < 2)
		return ;
	temp = stack_pop_bottom(vals->stack_a);
	stack_push_top(vals->stack_a, temp);
	if (num == 1)
		ft_printf("rra\n");
}
