/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:31:54 by maolivei          #+#    #+#             */
/*   Updated: 2023/04/25 13:33:11 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const unsigned char	*us = (unsigned char *)s;
	const unsigned char	uc = (unsigned char)c;
	unsigned char		*match;

	match = NULL;
	while (*us)
		if (*us++ == uc)
			match = (unsigned char *)us - 1;
	return ((char *)match);
}
