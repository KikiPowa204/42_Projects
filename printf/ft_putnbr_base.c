/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:44:56 by knajmech          #+#    #+#             */
/*   Updated: 2025/10/25 11:24:22 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int  how_long(size_t num)
{
	size_t div;

	if (!num)
		return (0);
	div = 0;
	while (num > 0)
	{
		num /= 16;
		div++;
	}
	return (div);
}

void	recurse(size_t num, const char *dic, char *result, size_t len)
{
	if (num < 16)
	{
		result[len] = dic[num % 16];
		return ;
	}
	recurse(num / 16, dic, result, len - 1);
	result[len] = dic[num % 16];
}

char*	ft_putnbr_base(size_t nbr)
{
	size_t			len;
	size_t			num;
	const char		*map;
	char			*result;

	num = nbr;
	len = how_long(num);
	result = ft_calloc(len + 1, sizeof(char));
	map = "0123456789ABCDEF";
	recurse(num, map, result, len - 1);
	return (result);
}
/*int	main(void)
{
	char base[] = "01";
	int num = -21;

	ft_putnbr_base(num, base);
}*/
