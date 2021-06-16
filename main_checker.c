/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 21:46:03 by fsarbout          #+#    #+#             */
/*   Updated: 2021/06/16 20:53:39 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	int hadak;
	
	
	a = new_stack(argc, argv);
	hadak = del_first_node(&a);
	b = new_stack(argc, argv);
	// swap(&a);
	// push(&a , &b);
	rotate(&a , &b);
	print_list(&a);
	printf("heeyyyy\n"   );
	print_list(&b);
	is_sorted(a);
	
}

void	exit_(t_stack **stack,char *string, int error)
{
	if (error == 1)
		ft_putstr("Error\n");
	if (error == 0)
		ft_putendl_fd(GREEN, STDOUT_FILENO);
	if (error == 2)
		ft_putendl_fd(RED, STDOUT_FILENO);
	ft_putstr(string);
	if (error == 1)
		clear_list(stack);
	exit(0);
}

