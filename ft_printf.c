/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:20:09 by knajmech          #+#    #+#             */
/*   Updated: 2025/10/24 10:39:04 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.a"

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

void *redirect(char spec, va_list arg)
{
	char	*x;
	int		i;

	else if (spec == 'd' || spec == 'i')
		x = ft_itoa(va_arg(arg, int));
	else if (spec == 'c')
		x = va_arg(arg, char);
	else if (spec == 's')
		x = va_arg(arg, char*);
	else if (spec == 'u')
		x = ft_itoa(va_arg(arg, unsigned int));
	else if (spec == 'x' || 'X')
	{
		i = 0;
		x = ft_putnbr_base(ft_itoa(va_arg(arg, unsigned int)));
		while(x[i])
		{
			if (spec == 'x')
				x[i] = ft_tolower(x[i]);
			i++;
		}
	}
	else if (spec == '%')
		return (va_arg(arg, char));
	return (x);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	char	*param;
	int		rv;
	int		num;

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
			rv += skipped_spaces;
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
	ft_printf("%s", "string");
}
