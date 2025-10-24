/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:20:09 by knajmech          #+#    #+#             */
/*   Updated: 2025/10/23 15:03:23 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
	if (spec == 'd')
		return (ft_itoa(va_arg(arg, int)));
	if (spec == 'c')
		return (va_arg(arg, char));
	if (spec == 's')
		return (va_arg(arg, char*));
	if (spec == 'i')
		return (ft_itoa(va_arg(arg, int)));
	if (spec == 'u')
		return (ft_itoa(va_arg(arg, unsigned int)));
	if (spec == 'x')
		return (ft_itoa(va_arg(arg, unsigned int)));
	if (spec == 'X')
		return (ft_itoa(va_arg(arg, unsigned int)));
	if (spec == '%')
		return (va_arg(arg, char));
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
