/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:11:38 by fsarbout          #+#    #+#             */
/*   Updated: 2021/06/23 19:53:46 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>
// #inlcude <>
// /*
// ** from : https://hackr.io/blog/quick-sort-in-c
// */

void ft_swap(int* a, int* b)
{
	int t;
	t  = *a;
	*a = *b;
	*b = t;
}

int partition (int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);


	for (int j = low; j <= high- 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			ft_swap(&arr[i], &arr[j]);
		}
	}
	ft_swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
	int pi = partition(arr, low, high);
	quickSort(arr, low, pi - 1);
	quickSort(arr, pi + 1, high);
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
	printf("%d ", arr[i]);
	printf("n");
}

int main(int ac, char **av)
{
	t_stack *stack = new_stack(ac, av);
	int *arr = get_array(stack) ;
	int n = sizeof(*arr)/sizeof(arr[0]);
	quickSort(arr, 0, n-1);
	printf("The sorted array is: n");
	printArray(arr, n);
	return 0;
}