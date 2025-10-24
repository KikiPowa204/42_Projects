/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:20:09 by knajmech          #+#    #+#             */
/*   Updated: 2025/10/24 14:55:50 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libftprintf.h"

static int  skip_space(const char *input)
{
	int i;

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

char *redirect(char spec, va_list arg)
{
	char	*x;
	int		i;

	x = 0;
	if (spec == 'd' || spec == 'i')
		return (ft_itoa(va_arg(arg, int)));
	if (spec == 'c')
		*x = va_arg(arg, int);
	else if (spec == 's')
		x = ft_strdup(va_arg(arg, char*));
	else if (spec == 'u')
		return (ft_itoa(va_arg(arg, unsigned int)));
	else if (spec == 'x' || spec == 'X' || spec == 'p')
	{
		i = 0;
		x = ft_putnbr_base(va_arg(arg, size_t));
		while(x[i])
		{
			if (spec == 'x')
				x[i] = ft_tolower(x[i]);
			i++;
		}
	}
	else if (spec == '%')
	{
		*x = va_arg(arg, int);
	}
	return (x);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	char	*param;
	int		rv;
	int		num;
	int		skipped_spaces;

	rv = 0;
	num = 0;
	va_start(arg, str);
	while (str[rv])
	{
		skipped_spaces = 0;
		if (str[rv] == '%')
		{
			skipped_spaces = skip_space(&str[rv + 1]) + 1;
			param = redirect(str[rv + skipped_spaces], arg);
			num += (ft_strlen(param));
			ft_putstr_fd(param, 1);
			free(param);
			param = NULL;
			rv += skipped_spaces + 1;
		}
		else
		{
			ft_putchar_fd(str[rv], 1);
			rv++;
			num++;
		}
	}
	va_end(arg);
	return (num);
}

int main(void)
{
	char *str =  "string";

	printf("%     d\n", 235);
	ft_printf("this prints a string:%s and this prints its length %d\n", str, ft_strlen(str));
	ft_printf("this prints the address %p, and this prints its return value %d %i\n", str, ft_printf(str));
	ft_printf("this prints the hexadecimal value of 2345 - %x %X", 2345, 2345); 
}
