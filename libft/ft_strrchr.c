/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 22:33:26 by fsarbout          #+#    #+#             */
/*   Updated: 2019/11/01 01:59:25 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = 0;
	while (*(s + i))
		i++;
	while (*(s + i) != c && (i >= 0))
	{
		if (i == 0)
			return (NULL);
		i--;
	}
	return ((char *)(s + i));
}