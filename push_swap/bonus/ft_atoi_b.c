/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:50:45 by knajmech          #+#    #+#             */
/*   Updated: 2026/02/03 10:28:52 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	atoi_valid_b(char *nptr)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(nptr);
	if (!len)
		return (-1);
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (i < len)
	{
		if (nptr[i] > '9' || nptr[i] < '0')
			return (-1);
		i++;
	}
	return (1);
}

int	ft_atoi_b(char *nptr)
{
	long int	new;
	int			i;
	int			neg_switch;

	neg_switch = 0;
	new = 0;
	i = 0;
	if (atoi_valid_b(nptr) == -1)
		return (valid_address(-1, 's'), -1);
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
