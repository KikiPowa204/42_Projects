/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_nation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 08:59:26 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/09 10:15:34 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	like_a_record_baby(t_stack **head)
{
	*head = (*head)->next;
}

void	you_spin_me_round(t_stack **head)
{
	*head = (*head)->prev;
}

void	rrotate_both(t_manager *heads)
{
	you_spin_me_round(&(heads)->head_a);
	you_spin_me_round(&(heads)->head_b);
}

void	rotate_both(t_manager *heads)
{
	like_a_record_baby(&(heads)->head_a);
	like_a_record_baby(&(heads)->head_b);
}

void	crack_safe(t_manager *heads, int num)
{
	if (num == 4)
		like_a_record_baby(&(heads)->head_a);
	if (num == 5)
		like_a_record_baby(&(heads)->head_b);
	if (num == 6)
		rotate_both(heads);
}