/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 08:37:36 by knajmech          #+#    #+#             */
/*   Updated: 2026/02/02 11:58:11 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "printf/ft_printf.h"
# include "printf/libft/libft.h"
# include "./bonus/get_next_line.h"

typedef struct s_manager
{
	t_stack	*head_a;
	t_stack	*head_b;
	t_stack	*first_pos;
	t_stack	*target_in_a;
	t_stack	*target_in_b;
	int		win_inst[20];
	int		inst[20];
	int		size_a;
	int		size_b;
	int		cost;
	int		is_split;
}			t_manager;

int		sort_seven(t_manager *heads);
int		check_valid(char **argv, int amount);
int		stack_manager(t_manager *heads, char **argv, int check);
int		*r_array(int *nums, int size);
int		*rr_array(int *nums, int size);
int		*swap_array(int *nums);
int		arr_size(int *nums);
char	*read_map(int path);
int		main(int argc, char **argv);
int		checker(t_stack *stack, t_manager *heads);
void	find_ft(t_manager *heads, t_stack *starting, t_stack *stack_b);
void	cost_to_top(t_stack *node, int size, int i);
void	rrotate(t_stack **stack, t_manager *heads, char a_or_b);
void	rotate(t_stack **stack, t_manager *heads, char a_or_b);
void	freaky_friday(t_stack **head, char a_o_b);
void	order_stacks(t_manager *heads, int *path);
void	parent_trap(t_manager *heads);
void	push_a(t_manager *heads);
void	push_b(t_manager *heads);
void	rrotate_both(t_manager *heads);
void	rotate_both(t_manager *heads);
void	pick_path(t_manager *heads, int num);
void	crack_safe(t_manager *heads, int num);
void	unload(t_manager *heads);
void	post_station(t_manager *heads, char instruction);
void	calculator(t_manager *heads);
void	switcheroo(t_manager *heads);
void	check_rotation(t_manager *heads, int cost_to_top);
int		it_is_cheap(t_manager *heads, t_stack *stack_1, t_stack *stack_2);
void	to_r_or_rr(t_manager *heads, t_stack *head,
			t_stack *target, char stack);
void	move_to_position(t_manager *heads, int ctt_a, int ctt_b);
void	purge(char **list, int s_split);

//bonus functions
int		make_list_b(t_manager *heads, char **argv);
int		index_list_b(t_stack *stack_a, t_manager *heads, int start);
void	spin_rev_b(t_stack *stack, t_stack *head);
int		checker_b(t_stack *stack, t_manager *heads);
int		valid_address_b(int compare, char s_or_l);
int		ft_atoi_b(char *nbr);
void	execute_rule(t_manager *heads, int rule);
int		assign_val(char *instruction, int move);

#endif