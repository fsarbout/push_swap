/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 21:46:03 by fsarbout          #+#    #+#             */
/*   Updated: 2021/06/25 19:25:01 by fsarbout         ###   ########.fr       */
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
	char *instruction;
	int gnl_ret;
	
	if (ac >= 2)
	{
		b = NULL;
		a = new_stack(ac, av);
		while (get_next_line(0, &instruction))
		{
			gnl_ret = apply_instruction(instruction, &a, &b);
			free(instruction);
			if (gnl_ret == -1)
				return (-1);
			/***********************************************/	
			// printf("************************************\n");
			// printf("LIST A : \n");
			// print_list(&a);
			// printf("**********************\n");
			// printf("LIST B : \n");
			// print_list(&b);
			// printf("************************************\n");
			/***********************************************/
			// visualize(a, b);
		}
		if (is_sorted(a) && !b)
			exit_(&a, 0, "OK", 0);
		else
			exit_(&a, 0, "KO", 2);
	}
	return (0);
}