/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:15:39 by rdelicad          #+#    #+#             */
/*   Updated: 2023/08/18 17:51:35 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstswap(t_list **stack)
{
	t_list		*swap;

	swap = NULL;
	if (ft_lstsize(*stack) <= 1)
		return ;
	else
	{
		swap = (*stack)->next;
		(*stack)->next = (*stack)->next->next;
		(*stack)->next->next = swap;
	}
}
