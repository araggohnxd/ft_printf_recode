/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 00:05:00 by maolivei          #+#    #+#             */
/*   Updated: 2023/04/25 13:43:24 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	const size_t	length = ft_strlen(s);
	char			*dup;

	dup = (char *)malloc(sizeof(char) * (length + 1));
	if (!dup)
		return (NULL);
	dup[length] = '\0';
	return ((char *)ft_memcpy(dup, s, length));
}
