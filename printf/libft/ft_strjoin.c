/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:17:01 by knajmech          #+#    #+#             */
/*   Updated: 2025/10/21 15:24:42 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_1;
	int		len_2;
	char	*new;

	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	new = malloc((len_1 + len_2 + 1) * sizeof(char));
	if (!new)
		return (0);
	ft_strlcpy(new, s1, len_1 + 1);
	ft_strlcat(new, s2, (len_1 + 1) + len_2);
	return (new);
}
