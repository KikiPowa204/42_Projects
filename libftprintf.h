/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:17:43 by knajmech          #+#    #+#             */
/*   Updated: 2025/10/24 10:36:15 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <libstf.h>
# include <stdarg.h>
# include <libft/libft.a>

int		ft_printf(const char *, ...);
void	ft_putnbr_base(int nbr, char *base);

#endif
