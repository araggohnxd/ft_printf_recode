/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:42:58 by maolivei          #+#    #+#             */
/*   Updated: 2023/05/17 16:02:13 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	const size_t	length = ft_strnlen(s, n);
	char			*dup;

	dup = (char *)malloc(sizeof(char) * (length + 1));
	if (!dup)
		return (NULL);
	dup[length] = '\0';
	return ((char *)ft_memcpy(dup, s, length));
}
