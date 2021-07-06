/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_and_exit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:11:38 by fsarbout          #+#    #+#             */
/*   Updated: 2021/07/06 11:40:18 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** https://hackr.io/blog/quick-sort-in-c
*/

void ft_swap(int* a, int* b)
{
	int t;
	t  = *a;
	*a = *b;
	*b = t;
}

int partition (int arr[], int low, int high)
{
	int pivot;
	int i;
	int j;
	
	pivot = arr[high];
	i = (low - 1);
	j = low;
	while (j <= high - 1)
	{
		if (arr[j] <= pivot)
		{
			i++;
			ft_swap(&arr[i], &arr[j]);
		}
		j++;
	}
	ft_swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

int *quick_sort(int *arr, int low, int high)
{
	int pi;
	
	if (low < high)
	{
		pi = partition(arr, low, high);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	} 
	return (arr);
}

void print_array(int *arr, int size)
{
	int i;
	for (i=0; i < size; i++)
	printf("%d ", arr[i]);
	printf("\n");
}

void	exit_(t_stack **a,t_stack **b ,char *string, int error)
{
	if (error == 1)
		ft_putstr("Error\n");
	if (error == 0)
		ft_putendl_fd(GREEN, STDOUT_FILENO);
	if (error == 2)
		ft_putendl_fd(RED, STDOUT_FILENO);
	ft_putstr(string);
	(void)a;
	(void)b;
	if (error == 1)
		exit(1);
	// system("leaks push_swap");
	exit(0);
}