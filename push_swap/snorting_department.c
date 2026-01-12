/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snorting_department.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 09:47:34 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/09 11:53:30 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void unload(t_manager *heads)
{
    // Use the struct variable instead of calculating the size every time
    while (heads->size_a > 7)
    {
        // post_station handles the "Sentinel Skip" (ra/rra) 
        // AND the push_b.
        post_station(heads, 'b');
        
        // Safety check: if post_station just rotates, 
        // size_a doesn't change. The loop continues 
        // until a non-sentinel is found and pushed.
    }
}