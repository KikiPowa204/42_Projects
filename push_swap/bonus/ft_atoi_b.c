/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:50:45 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/22 09:53:01 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	atoi_valid_b(long new, char *nptr)
{
	int	i;
	int	len;
	int	valid;

	i = 0;
	valid = 1;
	len = ft_strlen(nptr);
	if (new > INT_MAX || new < INT_MIN)
		valid = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (i < len)
	{
		if (nptr[i] > '9' || nptr[i] < '0')
			valid = -1;
		i++;
	}
	if (valid == -1)
		valid_address_b(valid, 's');
	return (valid);
}

int	ft_atoi_b(char *nptr)
{
	long int	new;
	int			i;
	int			neg_switch;

	neg_switch = 0;
	new = 0;
	i = 0;
	if (atoi_valid_b(new, nptr) == -1)
		valid_address_b(-1, 's');
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg_switch = 1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		new += nptr[i] - '0';
		i++;
		if (nptr[i] <= '9' && nptr[i] >= '0')
			new *= 10;
	}
	if (neg_switch)
		new *= -1;
	return (new);
}
