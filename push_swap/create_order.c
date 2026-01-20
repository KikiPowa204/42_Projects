/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_order.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:24:38 by knajmech          #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2026/01/18 12:24:34 by knajmech         ###   ########.fr       */
=======
/*   Updated: 2026/01/20 12:00:44 by knajmech         ###   ########.fr       */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

<<<<<<< Updated upstream
void focus_category(t_stack *stack_b, t_manager *heads)
{
	int	size;
	int	i;

	if (heads->max == 15)
		return ;
	i = 0;
	size = (heads->max) / 2;
	while (i++ < size)
		stack_b = stack_b->prev;
	if(stack_b->index > stack_b->next->index)
		to_r_or_rr(heads, heads->head_b, stack_b, 'b');
	else if (stack_b->prev->index > stack_b->next->next->index)
		to_r_or_rr(heads, heads->head_b, stack_b->prev, 'b');
	cost_to_top(heads->head_b, heads->size_b, 0);
	cost_to_top(heads->head_a, heads->size_a, 0);
	//heads->category = stack_b;
}

void order_stacks(t_manager *heads, int *path)
=======
void	find_optimal(t_manager *heads, t_stack *stack_a)
{
	t_stack	*current;
	int		i;
	int		j;
	int		biggest_group;

	i = 0;
	heads->target_in_a = NULL;
	biggest_group = 20;
	while (i++ < heads->size_a)
	{
		j = 0;
		current = stack_a;
		if (stack_a->index < stack_a->next->index)
		{

			if (j > biggest_group)
			{
				biggest_group++;	
				heads->target_in_a = current;
			}
			j++;
		}
		stack_a = stack_a->next;
	}
}

void	order_stacks(t_manager *heads, int *path)
>>>>>>> Stashed changes
{
	int		i;

	i = 0;
	while ((path[i]))
	{
		if (path[i] <= 3 && path[i] >= 1)
			pick_path(heads, path[i]);
		if (path[i] >= 4 && path[i] <= 6)
			crack_safe(heads, path[i]);
		if (path[i] == 7)
			you_spin_me_round(&(heads)->head_a, heads, 'a');
		if (path[i] == 8)
			you_spin_me_round(&(heads)->head_b, heads, 'b');
		if (path[i] == 9)
			rrotate_both(heads);
		if (path[i] == 10)
			push_a(heads);
		if (path[i] == 11)
			push_b(heads);
		i++;
	}
}
<<<<<<< Updated upstream
=======

void	unload(t_manager *heads)
{
	// find_optimal(heads, heads->head_a);
	// if (heads->target_in_a)
	// {
	// 	cost_to_top(heads->head_a, heads->size_a, 0);
	// 	while (heads->target_in_a != heads->head_a)
	// 		to_r_or_rr(heads, heads->head_a, heads->target_in_a, 'a');
	// }
	if (!(checker(heads->head_a, heads)))
		while (heads->size_a > 7)
		{
			if (heads->head_a->index == 1)
				like_a_record_baby(&(heads)->head_a, heads, 'a');
			else
				post_station(heads, 'b');
		}
}
>>>>>>> Stashed changes
