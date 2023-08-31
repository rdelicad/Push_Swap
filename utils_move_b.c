/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_move_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:12:50 by rdelicad          #+#    #+#             */
/*   Updated: 2023/08/18 16:31:34 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	move_node_b(t_list **stack_b, int b)
{
	if (b > 0)
		rotate_node_b(stack_b, b);
	else
	{
		reverse_node_b(stack_b, b);
	}
}

void	rotate_node_b(t_list **stack_b, int b)
{
	while (b > 0)
	{
		rotate_b(stack_b);
		b--;
	}
}

void	reverse_node_b(t_list **stack_b, int b)
{
	while (b < 0)
	{
		reverse_b(stack_b);
		b++;
	}
}
