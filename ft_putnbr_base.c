/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:44:56 by knajmech          #+#    #+#             */
/*   Updated: 2025/10/23 16:03:50 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int c)
{
	write(1, &c, 1);
}

void	recurse(int long base, int long num, char *dic)
{
	if (num < base)
	{
		print((dic[num % base]));
		return ;
	}
	recurse(base, num / base, dic);
	print(dic[num % base]);
}

void	ft_putnbr_base(int nbr)
{
	int long		len;
	int long		num;
	const char		*base;

	base = "0123456789ABCDEF";
	num = nbr;
	len = 0;
	recurse(16, num, base);
}

/*int	main(void)
{
	char base[] = "01";
	int num = -21;

	ft_putnbr_base(num, base);
}*/
