/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:52:57 by junseyun          #+#    #+#             */
/*   Updated: 2024/08/16 14:53:28 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int val)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!(new_node))
		exception_msg();
	new_node->data = val;
	new_node->idx = 0;
	new_node->next = 0;
	new_node->prev = 0;
	return (new_node);
}

void	push_zero_stack(t_stack *stack, t_node *node)
{
	stack->top = node;
	stack->bottom = node;
}

void	pop_zero_stack(t_stack *stack)
{
	stack->top = 0;
	stack->bottom = 0;
}
