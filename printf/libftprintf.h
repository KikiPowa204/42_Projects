/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:17:43 by knajmech          #+#    #+#             */
/*   Updated: 2025/10/27 13:57:04 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *, ...);
char	*ft_putnbr_base(size_t nbr);

#endif
