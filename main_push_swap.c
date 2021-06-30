/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 21:46:06 by fsarbout          #+#    #+#             */
/*   Updated: 2021/06/30 10:59:00 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void visualize(t_stack *a, t_stack *b)
{
	t_stack *curr_a;
	t_stack *curr_b;

	int size_a = list_lenght(a);
	int size_b = list_lenght(b);
	int size = (size_a > size_b) ? size_a : size_b;

	curr_a = a;
	curr_b = b;
	printf("%s", YEL);
	printf(" ----- STACK_A -----   ||   ----- STACK_B -----\n");
	write(1, WHT, ft_strlen(WHT));
	for (int i = 0; i < size; i++)
	{
		printf("%s||        %-10s|| ~ ||        %-10s||\n", BLU, (size_a > i) ? ft_itoa(curr_a->nb) : " ", (size_b > i) ? ft_itoa(curr_b->nb) : " ");
		if (a && curr_a->next != NULL)
			curr_a = curr_a->next;
		if (b && curr_b->next != NULL)
			curr_b = curr_b->next;
	}
	printf("%s", YEL);
	printf("-----------------------------------------------\n");
	write(1, WHT, ft_strlen(WHT));
}

int main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;
	
	// int *array;
	if (ac >= 2)
	{
		b = NULL;
		a = new_stack(ac, av);
		// array = get_array(a);affect ::::::;1
		if (!is_sorted(a))
			push_swap(&a, &b, ac - 1);
		visualize(a, b);
	}
	exit_(&a,&b,0,5);
} 