/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 22:01:34 by maolivei          #+#    #+#             */
/*   Updated: 2023/04/24 19:34:50 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const size_t	ndl_len = ft_strlen(needle);

	if (!ndl_len)
		return ((char *)haystack);
	while (*haystack && len)
	{
		if (ndl_len > len--)
			return (NULL);
		if (*haystack == *needle && ft_strncmp(haystack, needle, ndl_len) == 0)
			return ((char *)haystack);
		++haystack;
	}
	return (NULL);
}
