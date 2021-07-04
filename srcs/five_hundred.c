/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:40:55 by fsarbout          #+#    #+#             */
/*   Updated: 2021/07/04 19:50:02 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_500(t_stack **a, t_stack **b)
{

	// int i = get_closest_min_index(*a , 5 , 20);
	// printf("%d\n", i);
	while (*a)
	{ 
		int lenght_a = list_lenght(*a);
		int middle = get_middle(*a, lenght_a , 16);
		if (lenght_a <= 16 )
			push(a,b ,2);
		else
			move_mins_to_b(a, b, 6 , middle);
	}

	while (*b)
	{
		int max_index;

		max_index = get_min_max_index(*b, '+');
		while (max_index--)
			rotate(b, 2);
		push(b, a, 1);
		
	}

}