/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:53:48 by junseyun          #+#    #+#             */
/*   Updated: 2024/08/16 14:54:38 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*stack_pop_top(t_stack *stack)
{
	t_node	*temp;

	temp = stack->top;
	if (stack->size == 1)
		pop_zero_stack(stack);
	else if (stack->size == 2)
	{
		stack->top->next = 0;
		stack->top->prev = 0;
		stack->top = stack->bottom;
		stack->bottom->next = stack->top;
		stack->bottom->prev = stack->top;
	}
	else
	{
		stack->top = stack->top->next;
		stack->top->prev = stack->bottom;
		stack->bottom->next = stack->top;
	}
	temp->prev = 0;
	temp->next = 0;
	stack->size--;
	return (temp);
}

t_node	*stack_pop_bottom(t_stack *stack)
{
	t_node	*temp;

	temp = stack->bottom;
	if (stack->size == 1)
		pop_zero_stack(stack);
	else if (stack->size == 2)
	{
		stack->bottom->next = 0;
		stack->bottom->prev = 0;
		stack->bottom = stack->top;
		stack->top->next = stack->bottom;
		stack->top->prev = stack->bottom;
	}
	else
	{
		stack->bottom = stack->bottom->prev;
		stack->bottom->next = stack->top;
		stack->top->prev = stack->bottom;
	}
	temp->next = 0;
	temp->prev = 0;
	stack->size--;
	return (temp);
}

void	stack_push_top(t_stack *stack, t_node *node)
{
	if (!(node))
		exception_msg();
	if (stack->size == 0)
		push_zero_stack(stack, node);
	else if (stack->size == 1)
	{
		stack->bottom->prev = node;
		node->next = stack->bottom;
		stack->bottom->next = node;
		node->prev = stack->bottom;
		stack->top = node;
	}
	else
	{
		stack->top->prev = node;
		node->next = stack->top;
		stack->bottom->next = node;
		node->prev = stack->bottom;
		stack->top = node;
	}
	stack->size++;
}

void	stack_push_bottom(t_stack *stack, t_node *node)
{
	if (!(node))
		exception_msg();
	if (stack->size == 0)
		push_zero_stack(stack, node);
	else if (stack->size == 1)
	{
		stack->top->next = node;
		stack->top->prev = node;
		node->prev = stack->top;
		node->next = stack->top;
		stack->bottom = node;
	}
	else
	{
		stack->bottom->next = node;
		node->prev = stack->bottom;
		stack->top->prev = node;
		node->next = stack->top;
		stack->bottom = node;
	}
	stack->size++;
}
