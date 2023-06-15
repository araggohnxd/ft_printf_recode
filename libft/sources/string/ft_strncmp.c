/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:35:38 by maolivei          #+#    #+#             */
/*   Updated: 2023/04/25 13:30:16 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*us1 = (unsigned char *)s1;
	const unsigned char	*us2 = (unsigned char *)s2;

	while ((*us1 || *us2) && n--)
		if (*us1++ != *us2++)
			return (*(us1 - 1) - *(us2 - 1));
	return (0);
}
