/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 08:37:36 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/09 12:43:16 by knajmech         ###   ########.fr       */
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
    t_stack *head_a;
    t_stack *head_b;
    int     size_a;
    int     size_b;
    int     target_a;
    int     target_b;
    int     *cost;
    int     operation;
}               t_manager;

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
void	you_spin_me_round(t_stack **heads);
void	like_a_record_baby(t_stack **heads);
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