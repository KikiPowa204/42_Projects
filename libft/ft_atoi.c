/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:50:45 by knajmech          #+#    #+#             */
/*   Updated: 2025/10/21 09:26:40 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	skip_space(const char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if ((input[i] >= 9 && input[i] <= 13) || input[i] == 32)
			i++;
		else
			return (i);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	long int	new;
	int			i;
	int			neg_switch;

	neg_switch = 0;
	new = 0;
	i = skip_space(nptr);
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
