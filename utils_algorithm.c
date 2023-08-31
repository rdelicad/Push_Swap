/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:37:48 by lxuxer            #+#    #+#             */
/*   Updated: 2023/08/18 16:29:30 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	algorithm(t_list **stack_a, t_list **stack_b, t_struct result)
{
	int	medi;

	medi = median(result.argsi, result.len);
	if (!is_sorted(*stack_a))
	{
		if (ft_lstsize(*stack_a) == 2)
		{
			swap_a(stack_a);
		}
		else if (ft_lstsize(*stack_a) == 3)
		{
			tiny_sort(stack_a, stack_b);
		}
		else if (ft_lstsize(*stack_a) > 3)
		{
			if (ft_lstsize(*stack_a) > 3 && ft_lstsize(*stack_a) < 12)
				algorithm_medium(stack_a, stack_b, medi);
			else if (ft_lstsize(*stack_a) > 11)
				two_towers(stack_a, stack_b);
			tiny_sort(stack_a, stack_b);
			while ((*stack_b) != NULL)
				two_towers1(stack_a, stack_b);
			two_towers2(stack_a);
		}
	}
}

void	tiny_sort(t_list **stack_a, t_list **stack_b)
{
	int	a;
	int	b;
	int	c;

	(void)*stack_b;
	while (!is_sorted(*stack_a))
	{
		a = *((*stack_a)->content);
		b = *((*stack_a)->next->content);
		c = *((*stack_a)->next->next->content);
		if (a > b && a < c)
			swap_a(stack_a);
		else if (a > b && a > c)
			rotate_a(stack_a);
		else if ((a < b && a > c) || (a < b && a < c && b > c))
			reverse_a(stack_a);
	}
}

void	two_towers(t_list **stack_a, t_list **stack_b)
{
	ft_split_stack(stack_a, stack_b);
}

void	two_towers1(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;
	t_cost	c;

	c.target_b = get_min_cost(*stack_a, *stack_b);
	c.target_a = search_target_a(stack_a, c.target_b);
	current = *stack_b;
	while (current != NULL)
	{
		if (current->target == c.target_b)
		{
			c.costa = current->costa;
			c.costb = current->costb;
			break ;
		}
		current = current->next;
	}
	move(stack_a, stack_b, c.costa, c.costb);
}

void	two_towers2(t_list **stack_a)
{
	int	index;
	int	mid;

	index = get_target_index(*stack_a, 1);
	mid = ft_lstsize(*stack_a) / 2;
	if (index < mid)
	{
		while ((*stack_a)->target != 1)
			rotate_a(stack_a);
	}
	else
	{
		while ((*stack_a)->target != 1)
			reverse_a(stack_a);
	}
}
