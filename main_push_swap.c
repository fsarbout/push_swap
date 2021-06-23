/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 21:46:06 by fsarbout          #+#    #+#             */
/*   Updated: 2021/06/23 12:31:23 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;
	int i = 0;
	
	int *array;
	
	if (ac >= 2)
	{
		b = NULL;
		a = new_stack(ac, av);
		int lenght = list_lenght(a);
		printf("array lenght %d\n", lenght);
		array = get_array(a);
		while (i < lenght)
		{
			printf(" array %d\n" , array[i]);
			i++;
		}
		if (!is_sorted(a))
			push_swap(&a, &b, ac - 1);
		/***********************************************/
		printf("LIST A \n");
		print_list(&a);
		/***********************************************/

	}
	exit_(&a,&b,0,5);
}

