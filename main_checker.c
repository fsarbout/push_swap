/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 21:46:03 by fsarbout          #+#    #+#             */
/*   Updated: 2021/06/23 10:24:56 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

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
			printf("************************************\n");
			printf("LIST A : \n");
			print_list(&a);
			printf("**********************\n");
			printf("LIST B : \n");
			print_list(&b);
			printf("************************************\n");
			/***********************************************/
		}
		if (is_sorted(a) && !b)
			exit_(&a, 0, "OK", 0);
		else
			exit_(&a, 0, "KO", 2);
	}
	return (0);
}