/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:44:56 by knajmech          #+#    #+#             */
/*   Updated: 2025/08/05 12:38:05 by knajmech         ###   ########.fr       */
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

int	is_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int long	len;
	int long	num;

	num = nbr;
	len = 0;
	if (num < 0)
	{
		num *= -1;
		write(1, "-", 1);
	}
	if (!(is_valid(base)))
		return ;
	while (base[len])
		len++;
	recurse(len, num, base);
	return ;
}

/*/int	main(void)
{
	char base[] = "01";
	int num = -21;

	ft_putnbr_base(num, base);
}/*/
