/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:02:18 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/16 19:03:00 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrchr(void const *s, int c, size_t n)
{
	unsigned char const	*us = (unsigned char *)s;
	unsigned char const	uc = (unsigned char)c;

	while (n--)
		if (*(us + n) == uc)
			return ((void *)(us + n));
	return (NULL);
}
