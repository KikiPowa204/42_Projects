/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_nation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 08:59:26 by knajmech          #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2026/01/18 12:35:42 by knajmech         ###   ########.fr       */
=======
/*   Updated: 2026/01/20 11:54:28 by knajmech         ###   ########.fr       */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	like_a_record_baby(t_stack **stack, t_manager *heads, char a_or_b)
{
	*stack = (*stack)->next;
<<<<<<< Updated upstream
	if (a_or_b == 'b')
	{
		heads->head_b = *stack;
		ft_printf("rb\n");
	}
	else if (a_or_b == 'a')
	{
=======
	if (a_or_b == 'b' || a_or_b == 'B')
		heads->head_b = *stack;
	else if (a_or_b == 'a' || a_or_b == 'A')
>>>>>>> Stashed changes
		heads->head_a = *stack;
		ft_printf("ra\n");
	}
}

void	you_spin_me_round(t_stack **stack, t_manager *heads, char a_or_b)
{
	*stack = (*stack)->prev;
	if (a_or_b == 'b')
	{
		heads->head_b = *stack;
		ft_printf("rrb\n");
	}
	else if (a_or_b == 'a')
	{
		heads->head_a = *stack;
		ft_printf("rra\n");
	}
}

void	rrotate_both(t_manager *heads)
{
	heads->head_b = heads->head_b->prev;
	heads->head_a = heads->head_a->prev;
	ft_printf("rrr\n");
}

void	rotate_both(t_manager *heads)
{
	heads->head_b = heads->head_b->next;
	heads->head_a = heads->head_a->next;
	ft_printf("rr\n");
}

void	crack_safe(t_manager *heads, int num)
{
	if (num == 4)
		like_a_record_baby(&(heads)->head_a, heads, 'a');
	if (num == 5)
		like_a_record_baby(&(heads)->head_b, heads, 'b');
	if (num == 6)
		rotate_both(heads);
}