/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 21:46:03 by fsarbout          #+#    #+#             */
/*   Updated: 2021/06/21 22:36:13 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;
	char *instruction;
	int gnl_ret;
	// int *array;
	
	b = NULL;
	if (ac >= 2)
	{
		a = new_stack(ac, av);
		while (get_next_line(0, &instruction))
		{
			gnl_ret = apply_instruction(instruction, &a, &b);
			free(instruction);
			if (gnl_ret == -1)
				return (-1);
		}
		// 
		printf("min %d\n" ,get_min(a));
		printf("max %d\n" ,get_max(a));
		printf("lenght %d\n" ,list_lenght(a));
		// array = get_array(&a);
		printf("array %ls\n" ,get_array(a));
		printf("arrayuhuhe gewug\n");




		9-
		// if (array)
		// 	free(array);
		
		if (is_sorted(a) && !b)
			exit_(&a, 0, "OK", 0);
		else
			exit_(&a, 0, "KO", 2);
	}
	return (0);
}

void	exit_(t_stack **a,t_stack **b ,char *string, int error)
{
	(void)b;
	if (error == 1)
		ft_putstr("Error\n");
	if (error == 0)
		ft_putendl_fd(GREEN, STDOUT_FILENO);
	if (error == 2)
		ft_putendl_fd(RED, STDOUT_FILENO);
	ft_putstr(string);
	if (error == 1)
	{
		clear_list(a);
		clear_list(b);
	}
	exit(0);
}


