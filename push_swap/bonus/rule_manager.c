/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:45:15 by knajmech          #+#    #+#             */
/*   Updated: 2026/02/02 11:52:04 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	execute_rule(t_manager *heads, int rule)
{
	if (!rule)
		return ;
	if (rule <= 3 && rule >= 1)
		pick_path(heads, rule);
	if (rule >= 4 && rule <= 6)
		crack_safe(heads, rule);
	if (rule == 7)
		rrotate(&(heads)->head_a, heads, 'A');
	if (rule == 8)
		rrotate(&(heads)->head_b, heads, 'B');
	if (rule == 9)
		rrotate_both(heads);
	if (rule == 10)
		push_a(heads);
	if (rule == 11)
		push_b(heads);
}

int	assign_val(char *instruction, int move)
{
	if (!instruction)
		return (0);
	if (!(ft_memcmp(instruction, &("sa\n"), 3)))
		move = 1;
	else if (!(ft_memcmp(instruction, &("sb\n"), 3)))
		move = 2;
	else if (!(ft_memcmp(instruction, &("ss\n"), 3)))
		move = 3;
	else if (!(ft_memcmp(instruction, &("ra\n"), 3)))
		move = 4;
	else if (!(ft_memcmp(instruction, &("rb\n"), 3)))
		move = 5;
	else if (!(ft_memcmp(instruction, &("rr\n"), 4)))
		move = 6;
	else if (!(ft_memcmp(instruction, &("rra\n"), 4)))
		move = 7;
	else if (!(ft_memcmp(instruction, &("rrb\n"), 3)))
		move = 8;
	else if (!(ft_memcmp(instruction, &("rrr\n"), 4)))
		move = 9;
	else if (!(ft_memcmp(instruction, &("pa\n"), 3)))
		move = 10;
	else if (!(ft_memcmp(instruction, &("pb\n"), 3)))
		move = 11;
	return (move);
}
