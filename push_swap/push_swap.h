/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 08:37:36 by knajmech          #+#    #+#             */
/*   Updated: 2025/12/31 08:59:42 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include "printf/libft/libft.h"

/*typedef struct s_stack
{
    int             num;
    int             index;
    struct s_stack  *next;
}               t_stack;*/

typedef struct s_manager
{
    t_stack *head_a;
    t_stack *head_b;
    int     size_a;
    int     size_b;
    int     *cost;
    int     operation;   
}               t_manager;

void    sort_five(t_manager *heads);
int     check_valid(char **argv, int amount);
int     stack_manager(t_manager *heads, char **argv, int amount);
int     main(int argc, char **argv);
int     checker(t_stack *stack, t_manager *heads);