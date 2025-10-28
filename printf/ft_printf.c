/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:20:09 by knajmech          #+#    #+#             */
/*   Updated: 2025/10/28 10:31:47 by knajmech         ###   ########.fr       */
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

char	*just_hex_stuff(char *x, char spec ,va_list arg)
{
	int	i;

	i = 0;
	x = ft_putnbr_base(va_arg(arg, size_t));
	if (spec == 'p')
		write(1, "0x", 2);
	while(x[i])
	{
		if (spec == 'x')
			x[i] = ft_tolower(x[i]);
		i++;
	}
	return (x);
}

static char *redirect(char spec, va_list arg)
{
	char	*x;

	x = 0;
	if (spec == 'd' || spec == 'i')
		return (ft_itoa(va_arg(arg, int)));
	else if (spec == 'u')
		return (ft_itoa(va_arg(arg, unsigned int)));
	else if (spec == 'x' || spec == 'X' || spec == 'p')
		x = just_hex_stuff(x, spec, arg);
	else if (spec == '%')
	{
		x = ft_strdup("%");
		va_arg(arg, int);
	}
	if (spec == 's')
	{
		x = ft_strdup(va_arg(arg, char*));
		if (!x)
			return (ft_strdup("(null)"));
	}
	return (x);
}

static int	parser(const char *str, int rv, int *num, va_list arg)
{
	char	*param;
	int		skipped_spaces;
	int		i;

	i = 0;
	skipped_spaces = 0;
	if (str[rv] == '%')
	{
		skipped_spaces = skip_space(&str[rv + 1]) + 1;
		if(str[rv + skipped_spaces] == 'c')
		{
			i = ft_putchar_fd(va_arg(arg, int), 1);
			(*num) += i;
		}
		else
		{
			param = redirect(str[rv + skipped_spaces], arg);
			*num += ft_strlen(param);
			ft_putstr_fd(param, 1);
			if (param)
			{
				free(param);
				param = NULL;
			}
		}
		rv += skipped_spaces + 1;
	}
	else
	{
		ft_putchar_fd(str[rv], 1);
		rv++;
		(*num)++;
	}
	return (rv);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		rv;
	int		num;

	rv = 0;
	num = 0;
	va_start(arg, str);
	while (str[rv])
		rv = parser(str, rv, &num, arg);
	va_end(arg);
	return (num);
}

int main(void)
{
	char *str =  "string";
	//char *str1 = NULL;
	int len = ft_strlen(str);
	ft_printf("this prints a string:%s and this prints its length %d\n", str, len);
	ft_printf("this prints the address %p, and this prints its return value %d %i\n", str, ft_strlen(str), len);
	printf("%p", str);
	//printf("%c", "love");
	ft_printf("%c %c %%", 'a', 'l');
	ft_printf("this prints the hexadecimal value of 2345: %x / %X\n", 2349, 2349);
}
