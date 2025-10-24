/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:44:56 by knajmech          #+#    #+#             */
/*   Updated: 2025/10/24 12:48:12 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int  how_long(long int num)
{
	int div;

	if (!num)
		return (0);
	div = 0;
	while (num > 0)
	{
		num /= 10;
		div++;
	}
	return (div);
}

void	recurse(int long num, const char *dic, char *result, int len)
{
	if (num < 16)
	{
		result[len] = dic[num];
		return ;
	}
	recurse(num / 16, dic, result, len--);
	result[len] = dic[num % 16];
}

char*	ft_putnbr_base(int nbr)
{
	int long		len;
	int long		num;
	const char		*map;
	char			*result;

	num = nbr;
	len = how_long(num);
	result = ft_calloc(len + 1, sizeof(char));
	map = "0123456789ABCDEF";
	recurse(num, map, result, len);
	return (result);
}
/*int	main(void)
{
	char base[] = "01";
	int num = -21;

	ft_putnbr_base(num, base);
}*/
