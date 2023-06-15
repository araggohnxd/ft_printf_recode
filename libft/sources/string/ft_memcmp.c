/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 21:35:26 by maolivei          #+#    #+#             */
/*   Updated: 2023/04/24 19:48:56 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*us1 = s1;
	const unsigned char	*us2 = s2;

	while (n--)
		if (*us1++ != *us2++)
			return (*(us1 - 1) - *(us2 - 1));
	return (0);
}
