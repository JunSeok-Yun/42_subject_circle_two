/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ab_operate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:00:01 by junseyun          #+#    #+#             */
/*   Updated: 2024/08/16 15:00:05 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	rrr(t_vals *vals)
{
	rra(vals, 0);
	rrb(vals, 0);
	ft_printf("rrr\n");
}

void	ss(t_vals *vals)
{
	sa(vals, 0);
	sb(vals, 0);
	ft_printf("ss\n");
}

void	rr(t_vals *vals)
{
	ra(vals, 0);
	rb(vals, 0);
	ft_printf("rr\n");
}
