/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snorting_department.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 09:47:34 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/09 11:05:09 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void unload(t_manager *heads)
{
	while (ft_lstsize(heads->head_a) > 7)
	{
		post_station(heads, 'b');
	}
	heads->size_a = ft_lstsize(heads->head_a);
	heads->size_b = ft_lstsize(heads->head_b);
}