/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_move_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 12:25:58 by rdelicad          #+#    #+#             */
/*   Updated: 2023/08/18 16:30:29 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	move_node_a(t_list **stack_a, int a)
{
	if (a > 0)
		rotate_node_a(stack_a, a);
	else
	{
		reverse_node_a(stack_a, a);
	}
}

void	rotate_node_a(t_list **stack_a, int a)
{
	while (a > 0)
	{
		rotate_a(stack_a);
		a--;
	}
}

void	reverse_node_a(t_list **stack_a, int a)
{
	while (a < 0)
	{
		reverse_a(stack_a);
		a++;
	}
}
