/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:01:12 by junseyun          #+#    #+#             */
/*   Updated: 2024/08/17 16:36:15 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				data;
	int				idx;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int				size;
	struct s_node	*top;
	struct s_node	*bottom;
}	t_stack;

typedef struct s_vals
{
	int		size;
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_vals;

void	sa(t_vals *vals, int num);
void	ra(t_vals *vals, int num);
void	rra(t_vals *vals, int num);
void	pa(t_vals *vals);

void	sb(t_vals *vals, int num);
void	rb(t_vals *vals, int num);
void	rrb(t_vals *vals, int num);
void	pb(t_vals *vals);

void	ss(t_vals *vals);
void	rr(t_vals *vals);
void	rrr(t_vals *vals);

t_node	*create_node(int val);
void	push_zero_stack(t_stack *stack, t_node *node);
void	pop_zero_stack(t_stack *stack);

void	stack_push_top(t_stack *stack, t_node *node);
void	stack_push_bottom(t_stack *stack, t_node *node);
t_node	*stack_pop_top(t_stack *stack);
t_node	*stack_pop_bottom(t_stack *stack);
int		check_stack_arr(t_vals *vals, int *new_arr, int i, int flag);

void	exception_msg(void);
void	free_stack_all(t_vals *vals, int i);
void	free_str(char **res);

int		check_len(char **res, int i, int flag, int len);
int		check_digit_range(char **res, int i, int len);
int		check_sign_loc(char **res);
int		check_digit(char **res);
int		check_sign(char **res);
int		check_res(char **res);

void	sort(t_vals *vals);
void	radix_sort(t_vals *vals, int i, int j);
void	radix_sort_a(t_vals *vals, int i, int temp_idx);
void	indexing_val(t_vals *vals, int num, int next_num, int idx);
int		solve_max_bit(t_vals *vals, int temp_idx);

void	simple_sort_3(t_vals *vals, int top, int mid, int bottom);
void	simple_sort_4(t_vals *vals, int min_idx, int depth);
void	simple_sort_5(t_vals *vals, int min_idx, int depth);

int		ft_atoi(const char *str, char **res, int *stack_arr, t_vals *vals);
int		check_sep_all(char c);
char	**ft_split_arr(char *str, int *size);
char	**ft_split_arr_res(char **res, int n, int *size, char *str);
char	**ft_split(char *str);
char	**ft_split_res(char **res, int n, char *str);
void	check_arr(char *argv[], int flag, char **res);

#endif
