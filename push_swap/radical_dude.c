/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radical_dude.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 07:38:48 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/20 09:38:42 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	sortpush_b()
// {
	
// };

int	radix(t_manager *heads)
{
	int		size;
	int		i;
	int		max_bits;
	int		full_rotation;

	max_bits = 0;
	while (((heads->size_a - 1) >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits && !checker(heads->head_a, heads))
	{
		full_rotation = 0;
		size = heads->size_a;
		while (full_rotation++ < size)
		{
			if ((heads->head_a->index >> i) & 1)
				like_a_record_baby(&(heads->head_a), heads, 'a');
			else
				push_b(heads);
		}
		while (heads->size_b > 0)
			push_a(heads);
		i++;
	}
	return (1);
}

// int	radix(t_manager *heads)
// {
// 	int	i;
// 	int	j;
// 	int	size;
// 	int	max_bits;

// 	i = 0;
// 	max_bits = 0;
// 	// Calculate how many bits we need to check (e.g., 9 bits for 500)
// 	while (((heads->size_a - 1) >> max_bits) != 0)
// 		max_bits++;
// 	while (i < max_bits)
// 	{
// 		size = heads->size_a;
// 		j = 0;
// 		while (j < size)
// 		{
// 			// Check current bit
// 			if ((heads->head_a->index >> i) & 1)
// 				like_a_record_baby(&(heads->head_a), heads, 'a'); // ra
// 			else
// 				push_b(heads); // pb
// 			j++;
// 		}
// 		// Bring everything back for the next bit
// 		while (heads->size_b > 0)
// 			push_a(heads);
// 		// If sorted early, exit
// 		if (checker(heads->head_a, heads))
// 			return (1);
// 		i++;
// 	}
// 	return (1);
// }
