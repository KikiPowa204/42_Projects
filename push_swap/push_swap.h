/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 08:37:36 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/19 07:31:47 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include "printf/libft/libft.h"

static int g_winning_path[20];

// static int  g_sa = 1;
// static int  g_sb = 2;
// static int  g_ss = 3;
// static int  g_ra = 4;
// static int  g_rb = 5;
// static int  g_rr = 6;
// static int  g_rra = 7;
// static int  g_rrb = 8;
// static int  g_rrr = 9;
// static int  g_pa  = 10;
// static int  g_pb  = 11;

typedef struct s_manager
{
	t_stack	*head_a;
	t_stack	*head_b;
	t_stack	*first_pos;
	t_stack	*target_in_a;
	t_stack	*target_in_b;
	int		size_a;
	int		size_b;
	int		cost;
}			t_manager;


// function find_optimal_move
// current = head_b
// set target_in_b = current;
// set target_in_a = find_targed_in_a()
// set min_cost = current->cost_to_top + target_in_a->cost_to_top
// current = current->next;
// while (current != head_b)
// {
// 	if (check_min_cost(current) < heads->min_cost)
// 		then change managers min_cost
// 	else
// 		continue ;
// }

int		sort_seven(t_manager *heads);
int		check_valid(char **argv, int amount);
int		stack_manager(t_manager *heads, char **argv);
int		*r_array(int *nums, int size);
int		*rr_array(int *nums, int size);
int		*swap_array(int *nums);
int		arr_size(int *nums);
char	*read_map(int path);
int		main(int argc, char **argv);
int		checker(t_stack *stack, t_manager *heads);
void	find_ft(t_manager *heads, t_stack *starting, t_stack *stack_b);
void	cost_to_top(t_stack *node, int size, int i);
void	you_spin_me_round(t_stack **stack, t_manager *heads, char a_or_b);
void	like_a_record_baby(t_stack **stack, t_manager *heads, char a_or_b);
void	freaky_friday(t_stack **head);
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
void	to_r_or_rr(t_manager *heads, t_stack *head, t_stack *target, char stack);
void	form_categories(t_stack *b_nodes, t_stack *a_nodes, t_manager *heads);
void	move_to_position(t_manager *heads, int CTT_A, int CTT_B);