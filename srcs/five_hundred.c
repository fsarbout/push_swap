/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:40:55 by fsarbout          #+#    #+#             */
/*   Updated: 2021/07/05 16:40:14 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_500(t_stack **a, t_stack **b)
{

	// int i = get_closest_min_index(*a , 5 , 20);
	// printf("%d\n", i);
	int lenght_b;
	while (*a)
	{ 
		int lenght_a = list_lenght(*a);
		int middle = get_middle(*a, lenght_a , 16);
		if (lenght_a <= 16 )
			push(a,b ,2);
		else
			move_mins_to_b(a, b, middle);
	}

	while (*b)
	{
		int max_index;
		lenght_b = list_lenght(*b);
		max_index = get_min_max_index(*b, '+');
		if (max_index > lenght_b / 2)
		{
			// visualize(*a,*b);
			// printf ("max index %d \n", max_index);
			max_index = lenght_b - max_index;
			// printf ("lenght b %d \n", lenght_b);
			// printf ("max index %d \n", max_index);

			while (max_index-- > 0)
				reverse(b, 2);
			// printf ("max index %d \n", max_index);
			// print_list(a);
		}
		else
		{
			while (max_index-- > 0)
				rotate(b, 2);
		}
		push(b, a, 1);
		
	}

}


// void sort_500(t_stack **a, t_stack **b)
// {
// 	int lenght_a;
// 	int lenght_b;
// 	int middle;
// 	int min= get_min_or_max(*a, '-');

// 	(void)b;
// 	lenght_a = list_lenght(*a);
// 	middle = get_middle(*a, lenght_a ,16);
// 	move_mins_to_b(a, b,  middle);
// 	lenght_b = list_lenght(*b);
// 	sort_min_half(a, b, lenght_b);
// 	while (*a)
// 	{
// 		if ((*a)->nb == min)
// 			break;
// 		push(a,b,2);
// 	}
// 	lenght_b = list_lenght(*b);
// 	sort_min_half(a, b, lenght_b);
	
// 	// print_list(a);
// 	// printf("************\n");
// 	// print_list(b);
// }