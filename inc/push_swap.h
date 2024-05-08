/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyurchen <oyurchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:56:15 by oleg              #+#    #+#             */
/*   Updated: 2024/05/08 17:57:46 by oyurchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/libft.h"

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				is_cheapest;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

//! args utils
char			**split(char *s, char c);//
//! stack utils
int				stack_len(t_stack_node *stack);//
t_stack_node	*find_min(t_stack_node *stack);//
bool			stack_sorted(t_stack_node *stack);//
void			current_index(t_stack_node * stack);//
void			set_cheapest(t_stack_node *stack);//
t_stack_node	*get_cheapest(t_stack_node *stack);//
t_stack_node	*find_last(t_stack_node *stack);//
void			init_stack_a(t_stack_node **a, char **argv);//
void			init_nodes_a(t_stack_node *a, t_stack_node *b);//
void			init_nodes_b(t_stack_node *a, t_stack_node *b);//
t_stack_node	*find_max(t_stack_node *stack);//
void			prep_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name);//
//! errors handlers
int				error_duplicate(t_stack_node *a, int n);//
int				error_syntax(char *str_n);//
void			free_errors(t_stack_node **stack);//
void			free_stack(t_stack_node **stack);//
//! stack commands
void			sa(t_stack_node **a, bool print);//
void			sb(t_stack_node **b, bool print);//
void			ss(t_stack_node **a, t_stack_node **b, bool print);//
void			sort_three(t_stack_node **a);//
void			sort_stacks(t_stack_node **a, t_stack_node **b);//
void			ra(t_stack_node **a, bool print);//
void			rb(t_stack_node **b, bool print);//
void			rr(t_stack_node **a, t_stack_node **b, bool print);//
void			rrr(t_stack_node **a, t_stack_node *b, bool print);//
void			rrb(t_stack_node **b, bool print);//
void			rra(t_stack_node **a, bool print);//
void			pa(t_stack_node **a, t_stack_node **b, bool print);//
void			pb(t_stack_node **a, t_stack_node **b, bool print);//
#endif