/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:31:37 by junseyun          #+#    #+#             */
/*   Updated: 2024/08/16 14:33:47 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack_all(t_vals *vals, int i)
{
	t_node	*temp;
	t_node	*tmp;

	temp = vals->stack_a->top;
	while (i < vals->stack_a->size)
	{
		tmp = temp->next;
		free(temp);
		temp = tmp;
		i++;
	}
	free(vals->stack_a);
	i = 0;
	temp = vals->stack_b->top;
	while (i < vals->stack_b->size)
	{
		tmp = temp->next;
		free(temp);
		temp = tmp;
		i++;
	}
	free(vals->stack_b);
}

void	free_str(char **res)
{
	int	i;

	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
}

void	exception_msg(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
