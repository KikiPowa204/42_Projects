/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_seven.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 10:13:39 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/09 10:08:09 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_result(int *nums, int *path)
{
	int i;

	i = 0;
	while (nums[i])
	{
		//ft_printf("final nums:%d", nums[i]);
		i++;
	}
	i = 0;
	while (path[i])
	{
		ft_printf("%s\n", read_map(path[i]));
		i++;
	}
}

int *make_array (t_stack *stack_a, int size)
{
	int *nums;
	int i;

	nums = malloc((size + 2) * sizeof(int));
	if (!nums)
		return (0);
	i = 0;
	while (i < size)
	{
		nums[i] = stack_a->index;
		i++;
		stack_a = stack_a->next;
	}
	nums[i] = 0;
	return (nums);
}

int check_array(int *nums)
{
	int i;

	i = 0;
	while (nums[i])
	{
		if (nums[i] > nums[i + 1] && nums[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void    best_timeline(int *nums, int depth, int *min_moves, int *instructions)
{
	if (depth >= *min_moves)
		return ;
	if (check_array(nums))
	{
		if (depth < *min_moves)
		{
			ft_bzero(&instructions[depth + 1], (20 - depth) * sizeof(int));
			*min_moves = depth;
			ft_bzero(g_winning_path, 20 * sizeof(int));
			ft_memcpy(g_winning_path, instructions, (depth) * (sizeof(int)));
		}
		return ;
	}
	instructions[depth] = 1;
	nums = swap_array(nums);
	best_timeline(nums, depth + 1, min_moves, instructions);
	nums = swap_array(nums);
	instructions[depth] = 4;
	nums = rr_array(nums, arr_size(nums) - 1);
	best_timeline(nums, depth + 1, min_moves, instructions);
	nums = r_array(nums, arr_size(nums) - 1);
	instructions[depth] = 7;
	nums = r_array(nums, arr_size(nums) - 1);
	best_timeline(nums, depth + 1, min_moves, instructions);
	nums = rr_array(nums, arr_size(nums) - 1);
}

int sort_seven(t_manager *heads)
{
	int 	*nums;
	int		size;
	int		min_moves;
	int		instructions[20];

	min_moves = 20;
	if (checker(heads->head_a, heads))
		return (1);
	size = ft_lstsize(heads->head_a);
	nums = make_array(heads->head_a, size);
	if (!nums)
		return (ft_lstclear(&(heads->head_a)), 0);
	ft_memset(instructions, 0, (20 * sizeof(int)));
	best_timeline(nums, 0, &min_moves, instructions);
	print_result(nums, g_winning_path);
	order_stacks(heads, g_winning_path);
	free(nums);
	return (1);
}
